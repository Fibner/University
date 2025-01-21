library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity WashingMachine is
  port (
    Clk                 : in std_logic;
    InputMode           : in std_logic_vector (3 downto 0);
    SpecialMode         : in std_logic;
    InputStart          : in std_logic;
    InputPrevious       : in std_logic;
    InputNext           : in std_logic;
    InputChange         : in std_logic;
    DisplayOutputOne    : out std_logic_vector (6 downto 0); -- Wyjście powinno być 7-bitowe, tak jak w DisplayModule
    DisplayOutputTwo    : out std_logic_vector (6 downto 0);
    DisplayOutputThree  : out std_logic_vector (6 downto 0);
    DisplayOutputFour   : out std_logic_vector (6 downto 0);
    SpecialModeLed      : out std_logic;
    TempSelectorLed     : out std_logic;
    WhirpoolSelectorLed : out std_logic;
    EstaminatedTimeLed  : out std_logic
  );
end WashingMachine;

architecture rtl of WashingMachine is
  signal ProgramSelected : std_logic_vector(3 downto 0) := "0000";
  signal EstaminatedTime : integer range 0 to 95;
  signal TensDigitTime   : std_logic_vector(3 downto 0);
  signal OnesDigitTime   : std_logic_vector(3 downto 0);
  signal Works           : std_logic := '0';
  -- Sygnały do odliczania czasu w sekundach
  signal ClockFrequency : integer := 50; -- Zmienić na 50000000
  signal ClockCounter   : integer := 0;
  -- Własny tryb
  signal currentChange      : integer range 0 to 2      := 0;
  signal currentTemp        : integer range 20 to 90    := 50;
  signal currentWhirpool    : integer range 800 to 1200 := 1000;
  signal InputPrevious_prev : std_logic                 := '0';
  signal InputNext_prev     : std_logic                 := '0';
  signal InputChange_prev   : std_logic                 := '0';

  -- Sygnały do wyświetlania
  signal DataSendToDisplayOne   : std_logic_vector(3 downto 0);
  signal DataSendToDisplayTwo   : std_logic_vector(3 downto 0);
  signal DataSendToDisplayThree : std_logic_vector(3 downto 0);
  signal DataSendToDisplayFour  : std_logic_vector(3 downto 0);
  signal RotatingDisplay		  : std_logic_vector(3 downto 0);

  component DisplayModule
    port (
      VirtualHexInputOne    : in std_logic_vector (3 downto 0);
      VirtualHexOutputOne   : out std_logic_vector (6 downto 0);
      VirtualHexInputTwo    : in std_logic_vector (3 downto 0);
      VirtualHexOutputTwo   : out std_logic_vector (6 downto 0);
      VirtualHexInputThree  : in std_logic_vector (3 downto 0);
      VirtualHexOutputThree : out std_logic_vector (6 downto 0);
      VirtualHexInputFour   : in std_logic_vector (3 downto 0);
      VirtualHexOutputFour  : out std_logic_vector (6 downto 0)
    );
  end component;
  
  component RotatingModule
  port (
		clk : in std_logic;
		VirtualRotatingOut : out std_logic_vector (3 downto 0)
  );
  end component;

begin
  -- Instancja komponentu
  DisplayInstance : DisplayModule
  port map
  (
    VirtualHexInputOne    => DataSendToDisplayOne, -- Mapa wejścia
    VirtualHexOutputOne   => DisplayOutputOne, -- Mapa wyjścia
    VirtualHexInputTwo    => DataSendToDisplayTwo,
    VirtualHexOutputTwo   => DisplayOutputTwo,
    VirtualHexInputThree  => DataSendToDisplayThree,
    VirtualHexOutputThree => DisplayOutputThree,
    VirtualHexInputFour   => DataSendToDisplayFour,
    VirtualHexOutputFour  => DisplayOutputFour
  );
  
  RotatingInstance : RotatingModule
  port map
  (
		clk => clk,
		VirtualRotatingOut => RotatingDisplay
  );

  -- Proces SYNCHRONICZNY
  process (Clk)
  begin
    if rising_edge(Clk) then
      if InputStart = '1' and Works = '0' then
        Works <= '1';
      end if;

      if Works = '0' then -- Wyświetl menu jeśli pranie nie jest włączone
        if SpecialMode = '1' then -- Tryb własny prania
          InputChange_prev       <= InputChange;
          InputPrevious_prev     <= InputPrevious;
          InputNext_prev         <= InputNext;
          DataSendToDisplayOne   <= "1111";
          DataSendToDisplayTwo   <= "1111";
          DataSendToDisplayThree <= "1111";
          DataSendToDisplayFour  <= "1111";
          SpecialModeLed         <= '1';
          TempSelectorLed        <= '0';
          WhirpoolSelectorLed    <= '0';
          EstaminatedTimeLed     <= '0';
          case currentChange is
            when 0 =>
              TempSelectorLed        <= '1';
              DataSendToDisplayTwo   <= "1111";
              DataSendToDisplayThree <= std_logic_vector(to_unsigned(currentTemp / 10, 4));
              DataSendToDisplayFour  <= std_logic_vector(to_unsigned(currentTemp mod 10, 4));
            when 1 =>
              WhirpoolSelectorLed <= '1';
              if currentWhirpool < 1000 then
                DataSendToDisplayOne <= "1111";
              else
                DataSendToDisplayOne <= std_logic_vector(to_unsigned(currentWhirpool / 1000, 4));
              end if;
              DataSendToDisplayTwo   <= std_logic_vector(to_unsigned(currentWhirpool mod 1000 / 100, 4));
              DataSendToDisplayThree <= "0000";
              DataSendToDisplayFour  <= "0000";
            when 2 =>
              EstaminatedTimeLed     <= '1';
              DataSendToDisplayTwo   <= "1111";
              DataSendToDisplayThree <= std_logic_vector(to_unsigned(EstaminatedTime / 10, 4));
              DataSendToDisplayFour  <= std_logic_vector(to_unsigned(EstaminatedTime mod 10, 4));
            when others =>
              null;
          end case;

          if InputChange = '1' and InputChange_prev = '0' then -- Zmiana trybu
            currentChange <= currentChange + 1;
            if currentChange = 2 then
              currentChange <= 0;
            end if;
          end if;

          -- case
          if InputPrevious = '1' and InputPrevious_prev = '0' then -- Zmniejszanie wartości
            if currentChange = 0 then
              if currentTemp > 20 then
                currentTemp <= currentTemp - 10;
              end if;
            elsif currentChange = 1 then
              if currentWhirpool > 800 then
                currentWhirpool <= currentWhirpool - 100;
              end if;
            else
              if EstaminatedTime > 5 then
                EstaminatedTime <= EstaminatedTime - 5;
              end if;
            end if;
          end if;

          -- case
          if InputNext = '1' and InputNext_prev = '0' then -- Zwiększanie wartości
            if currentChange = 0 then
              if currentTemp < 90 then
                currentTemp <= currentTemp + 10;
              end if;
            elsif currentChange = 1 then
              if currentWhirpool < 1200 then
                currentWhirpool <= currentWhirpool + 100;
              end if;
            else
              if EstaminatedTime < 95 then
                EstaminatedTime <= EstaminatedTime + 5;
              end if;
            end if;
          end if;
        else
          SpecialModeLed  <= '0';
          ProgramSelected <= InputMode; -- Normalne tryby prania
          case InputMode is
            when "0000" =>
              EstaminatedTime <= 90; -- Bawełna
            when "0001" =>
              EstaminatedTime <= 60; -- Syntetyki
            when "0010" =>
              EstaminatedTime <= 45; -- Delikatne
            when "0011" =>
              EstaminatedTime <= 40; -- Wełna
            when "0100" =>
              EstaminatedTime <= 15; -- Szybkie 15
            when "0101" =>
              EstaminatedTime <= 70; -- Sport
            when "0110" =>
              EstaminatedTime <= 80; -- Antyalergiczne
            when "0111" =>
              EstaminatedTime <= 35; -- Pranie ręczne
            when others =>
              EstaminatedTime <= 95;
          end case;
          TensDigitTime          <= std_logic_vector(to_unsigned(EstaminatedTime / 10, 4));
          OnesDigitTime          <= std_logic_vector(to_unsigned(EstaminatedTime mod 10, 4));
          DataSendToDisplayOne   <= ProgramSelected;
          DataSendToDisplayTwo   <= "1111";
          DataSendToDisplayThree <= TensDigitTime;
          DataSendToDisplayFour  <= OnesDigitTime;
        end if;
      end if;

      if Works = '1' then
        ClockCounter <= ClockCounter + 1;
        if ClockCounter = ClockFrequency - 1 then -- Mineła sekunda
          EstaminatedTime <= EstaminatedTime - 1;
          if EstaminatedTime = 1 then -- Koniec prania
            Works <= '0';
          end if;
          ClockCounter  <= 0;
        end if;
		  DataSendToDisplayTwo <= RotatingDisplay;
		  TensDigitTime <= std_logic_vector(to_unsigned(EstaminatedTime / 10, 4));
          OnesDigitTime <= std_logic_vector(to_unsigned(EstaminatedTime mod 10, 4));
        DataSendToDisplayThree <= TensDigitTime;
        DataSendToDisplayFour  <= OnesDigitTime;
		  -- Czyszczenie sygnałów
		  TempSelectorLed        <= '0';
          WhirpoolSelectorLed    <= '0';
          EstaminatedTimeLed     <= '0';
      end if;

    end if;
  end process;
end rtl;
