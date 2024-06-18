library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity REJ is
   port
   (
      clk : in std_logic;
      DI : in signed (15 downto 0);
      BA : in signed (15 downto 0);
		  Sba : in signed (4 downto 0);
      Sbb : in signed (4 downto 0);
      Sbc : in signed (4 downto 0);
      Sid : in signed (2 downto 0);
      Sa : in signed (1 downto 0);
      BB : out signed (15 downto 0);
      BC : out signed (15 downto 0);
      ADR : out signed (31 downto 0);
      IRout : out signed (15 downto 0);
		  SbaToHex : OUT std_logic_vector (6 downto 0);
		  SbbToHex : OUT std_logic_vector (6 downto 0);
		  SbcToHex : OUT std_logic_vector (6 downto 0)
   );
end entity;
 
architecture rtl of REJ is
component display
	port
   (
      i : in std_logic_vector (4 downto 0);
      o : out std_logic_vector (6 downto 0)
	);
end component;
begin
	sbaD: display
		port map (
			i => std_logic_vector(Sba),
			o => SbaToHex
		);
	sbbD: display
    port map (
      i => std_logic_vector(Sbb),
      o => SbbToHex
		);
	sbcD: display
    port map (
      i => std_logic_vector(Sbc),
      o => SbcToHex
		);
process (clk, Sbb, Sbc, Sba, Sid, Sa, DI)
         variable IR, TMP, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14: signed (15 downto 0);
         variable AD, PC, SP, ATMP : signed (31 downto 0);
       begin
       if (clk'event and clk='1') then
         case Sid is
            when "001" =>
                PC := PC + 1;
            when "010" =>
                SP := SP + 1;
						when "011" =>
								SP := SP - 1;
						when "100" =>
								AD := AD + 1;
						when "101" =>
								AD := AD - 1;
            when others =>
                null;
         end case;
         case Sba is
             when "00000" => IR := BA;
             when "00001" => TMP := BA;
             when "00010" => R1 := BA;
             when "00011" => R2 := BA;
             when	"00100" => R3 := BA;
             when	"00101" => R4 := BA;
             when	"00110" => R5 := BA;
             when	"00111" => R6 := BA;
             when	"01000" => R7 := BA;
             when	"01001" => R8 := BA;
             when	"01010" => R9 := BA;
             when	"01011" => R10 := BA;
             when	"01100" => R11 := BA;
             when	"01101" => R12 := BA;
             when	"01110" => R13 := BA;
             when	"01111" => R14 := BA;
						 when "10000" => AD(15 downto 0) := BA;
						 when "10001" => AD(31 DOWNTO 16) := BA;
						 when "10010" => PC(15 DOWNTO 0) := BA;
						 when "10011" => PC(31 DOWNTO 16) := BA;
						 when "10100" => SP(15 DOWNTO 0) := BA;
						 when "10101" => SP(31 DOWNTO 16) := BA;
						 when "10110" => ATMP(15 DOWNTO 0) := BA;
						 when "10111" => ATMP(31 DOWNTO 16) := BA;
						 when others =>
                       null;
         end case;
         case Sbb is
             when "00000" => BB <= DI;
             when "00001" => BB <= TMP;
             when "00010" => BB <= R1;
             when "00011" => BB <= R2;
						 when "00100" => BB <= R3;
						 when "00101" => BB <= R4;
						 when "00110" => BB <= R5;
						 when "00111" => BB <= R6;
						 when "01000" => BB <= R7;
						 when "01001" => BB <= R8;
						 when "01010" => BB <= R9;
						 when "01011" => BB <= R10;
						 when "01100" => BB <= R11;
						 when "01101" => BB <= R12;
						 when "01110" => BB <= R13;
						 when "01111" => BB <= R14;
						 when "10000" => BB <= AD(15 downto 0);
						 when "10001" => BB <= AD (31 DOWNTO 16);
						 when "10010" => BB <= PC (15 DOWNTO 0);
						 when "10011" => BB <= PC(31 DOWNTO 16);
						 when "10100" => BB <= SP (15 DOWNTO 0); 
						 when "10101" => BB <= SP (31 DOWNTO 16); 
						 when "10110" => BB <= ATMP (15 DOWNTO 0);
						 when "10111" => BB <= ATMP (31 DOWNTO 16); 
						 when others =>
                       null;
 
         end case;
         case Sbc is
             when "00000" => BC <= DI;
             when "00001" => BC <= TMP;
             when "00010" => BC <= R1;
             when "00011" => BC <= R2;
             when	"00100" => BC <= R3;
             when	"00101" => BC <= R4;
             when	"00110" => BC <= R5;
             when	"00111" => BC <= R6;
             when	"01000" => BC <= R7;
             when	"01001" => BC <= R8;
             when	"01010" => BC <= R9;
             when	"01011" => BC <= R10;
             when	"01100" => BC <= R11;
             when	"01101" => BC <= R12;
             when	"01110" => BC <= R13;
             when	"01111" => BC <= R14;
						 when "10000" => BC <= AD(15 downto 0);
						 when "10001" => BC <= AD (31 DOWNTO 16);
						 when "10010" => BC <= PC (15 DOWNTO 0);
						 when "10011" => BC <= PC(31 DOWNTO 16);
						 when "10100" => BC <= SP (15 DOWNTO 0); 
						 when "10101" => BC <= SP (31 DOWNTO 16); 
						 when "10110" => BC <= ATMP (15 DOWNTO 0);
						 when "10111" => BC <= ATMP (31 DOWNTO 16); 
						 when others =>
                       null;
         end case;
         case Sa is
             when "00" => ADR <= AD;
             when "01" => ADR <= PC;
             when "10" => ADR <= SP;
             when "11" => ADR <= ATMP;
         end case;
         IRout <= IR;
       end if;
end process;
end rtl;