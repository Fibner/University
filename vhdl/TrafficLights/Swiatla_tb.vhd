library ieee;
use ieee.std_logic_1164.all;

entity Swiatla_tb is
end entity Swiatla_tb;

architecture Behavioral_tb of Swiatla_tb is
	signal clk : std_logic := '0';
	signal czerwone : std_logic := '1';
	signal pomaranczowe : std_logic := '0';
	signal zielone : std_logic := '0';

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
