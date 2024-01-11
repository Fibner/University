library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Swiatla is
    Port ( 
		clk : in STD_LOGIC;
        czerwone : out STD_LOGIC;
        pomaranczowe : out STD_LOGIC;
        zielone : out STD_LOGIC
		);
end Swiatla;

architecture Behavioral of Swiatla is
	signal count : integer range 0 to 11 := 0;
begin
	process(clk)
	begin
		if rising_edge(clk) or falling_edge(clk) then
			count <= count + 1;
		end if;
	end process;
	
	process(count)
	begin
		if count >= 0 and count < 5 then
			czerwone <= '1';
		else
			czerwone <= '0';
		end if;
		
		if count >= 4 and count < 5 then
			pomaranczowe <= '1';
		else
			pomaranczowe <= '0';
		end if;
		
		
		if count >= 5 and count < 12 then
			zielone <= '1';
		else
			zielone <= '0';
		end if;
	end process;
end Behavioral;