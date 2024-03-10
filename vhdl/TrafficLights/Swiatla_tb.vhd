library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Swiatla_tb is
end entity Swiatla_tb;

architecture Behavioral_tb of Swiatla_tb is
	signal clk : std_logic := '0';
	signal czerwone : std_logic;
	signal pomaranczowe : std_logic;
	signal zielone : std_logic;

begin
    uut1 : entity work.Swiatla
        port map (
			clk => clk,
			czerwone => czerwone,
			pomaranczowe => pomaranczowe,
			zielone => zielone
        );
						 
    process
    begin				   
        wait for 5 sec;
        clk <= not clk;
    end process;
	
end Behavioral_tb;
