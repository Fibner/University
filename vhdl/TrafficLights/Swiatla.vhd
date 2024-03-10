library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Swiatla is
    Port ( 
		clk : in STD_LOGIC;
        czerwone : out STD_LOGIC := '1';
        pomaranczowe : out STD_LOGIC := '0';
        zielone : out STD_LOGIC := '0'
		);
end Swiatla;

architecture Behavioral of Swiatla is
	type stan is (stan_czerwony, stan_pomaranczowy, stan_zielony);
	signal aktualny_stan, nastepny_stan : stan := stan_czerwony;
	signal licznik : integer range 0 to 11 := 0;
begin
	process(clk)
	begin
		if rising_edge(clk) or falling_edge(clk) then
			if licznik < 11 then
                licznik <= licznik + 1;
            else
                licznik <= 0;
            end if;
			aktualny_stan <= nastepny_stan;
		end if;
	end process;
	
	process(aktualny_stan, licznik)
	begin
		case aktualny_stan is
			when stan_czerwony =>
				czerwone <= '1';
                pomaranczowe <= '0';
                zielone <= '0';
				if licznik = 4 then 
					nastepny_stan <= stan_pomaranczowy;
				end if;
			when stan_pomaranczowy =>
				czerwone <= '1';
                pomaranczowe <= '1';
                zielone <= '0';
				if licznik = 5 then
					nastepny_stan <= stan_zielony;
				end if;
			when stan_zielony =>
				czerwone <= '0';
                pomaranczowe <= '0';
                zielone <= '1';
				if licznik = 11	then
					nastepny_stan <= stan_czerwony;
				end if;
		end case;
	end process;	
end Behavioral;