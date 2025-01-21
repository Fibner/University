library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity RotatingModule is
port(
		clk : in std_logic;
		VirtualRotatingOut : out STD_LOGIC_VECTOR (3 downto 0)
);
end RotatingModule;

architecture rtl of RotatingModule is
  signal ClockFrequency : integer := 50; -- Zmienić na 50000000
  signal ClockCounter   : integer := 0;
	signal counter : integer range 0 to 3 := 0;
begin

process (clk)
begin
			ClockCounter <= ClockCounter + 1;
        if ClockCounter = ClockFrequency/2 - 1 then -- Minęła sekunda
		  if counter <= 3 then
		  counter <= counter + 1;
		  else
		  counter <= 0;
		  end if;
          ClockCounter  <= 0;
        end if;

		case counter is
        when 0 => VirtualRotatingOut <= "1010";
        when 1 => VirtualRotatingOut <= "1011";
        when 2 => VirtualRotatingOut <= "1100";
        when 3 => VirtualRotatingOut <= "1101";
        when others => VirtualRotatingOut <= "XXXX";
    end case;
		
end process;
end rtl;