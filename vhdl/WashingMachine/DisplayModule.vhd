library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity DisplayModule is
port(
		VirtualHexInputOne : in STD_LOGIC_VECTOR (3 downto 0);
		VirtualHexInputTwo : in STD_LOGIC_VECTOR (3 downto 0);
		VirtualHexInputThree : in STD_LOGIC_VECTOR (3 downto 0);
		VirtualHexInputFour : in STD_LOGIC_VECTOR (3 downto 0);
		VirtualHexOutputOne : out STD_LOGIC_VECTOR (6 downto 0);
		VirtualHexOutputTwo : out STD_LOGIC_VECTOR (6 downto 0);
		VirtualHexOutputThree : out STD_LOGIC_VECTOR (6 downto 0);
		VirtualHexOutputFour : out STD_LOGIC_VECTOR (6 downto 0)
);
end DisplayModule;

architecture rtl of DisplayModule is
begin
	
	with VirtualHexInputOne select
		VirtualHexOutputOne <= "1000000" when "0000",
						 "1111001" when "0001",
						 "0100100" when "0010",
						 "0110000" when "0011",
						 "0011001" when "0100",
						 "0010010" when "0101",
						 "0000010" when "0110",
						 "1111000" when "0111",
						 "0000000" when "1000",
						 "0010000" when "1001",
						 "0001000" when "1010",
						 "0000011" when "1011",
						 "1000110" when "1100",
						 "0100001" when "1101",
						 "0000110" when "1110",
						 "1111111" when "1111",
						 "XXXXXXX" when others;
	with VirtualHexInputTwo select
		VirtualHexOutputTwo <= "1000000" when "0000",
						 "1111001" when "0001",
						 "0100100" when "0010",
						 "0110000" when "0011",
						 "0011001" when "0100",
						 "0010010" when "0101",
						 "0000010" when "0110",
						 "1111000" when "0111",
						 "0000000" when "1000",
						 "0010000" when "1001",
						 "1110111" when "1010",				-- Wyświetlanie obrotów
						 "1101111" when "1011",
						 "0111111" when "1100",
						 "1111011" when "1101",
						 "0000110" when "1110",
						 "1111111" when "1111",
						 "XXXXXXX" when others;
	with VirtualHexInputThree select
		VirtualHexOutputThree <= "1000000" when "0000",
						 "1111001" when "0001",
						 "0100100" when "0010",
						 "0110000" when "0011",
						 "0011001" when "0100",
						 "0010010" when "0101",
						 "0000010" when "0110",
						 "1111000" when "0111",
						 "0000000" when "1000",
						 "0010000" when "1001",
						 "0001000" when "1010",
						 "0000011" when "1011",
						 "1000110" when "1100",
						 "0100001" when "1101",
						 "0000110" when "1110",
						 "1111111" when "1111",
						 "XXXXXXX" when others;
	with VirtualHexInputFour select
		VirtualHexOutputFour <= "1000000" when "0000",
						 "1111001" when "0001",
						 "0100100" when "0010",
						 "0110000" when "0011",
						 "0011001" when "0100",
						 "0010010" when "0101",
						 "0000010" when "0110",
						 "1111000" when "0111",
						 "0000000" when "1000",
						 "0010000" when "1001",
						 "0001000" when "1010",
						 "0000011" when "1011",
						 "1000110" when "1100",
						 "0100001" when "1101",
						 "0000110" when "1110",
						 "1111111" when "1111",
						 "XXXXXXX" when others;
end rtl;