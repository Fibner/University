library ieee;
   use ieee.std_logic_1164.all;
   use ieee.std_logic_unsigned.all;
 
   entity dekoder7 is
   port (
         i : in bit_vector(4 downto 0);
         o : out std_logic_vector(6 downto 0)
   );
   end dekoder7;
 
   architecture behaviour of dekoder7 is
   begin
   with i select
          o <= "1110111" when "00000",
               "1110111" when "00001",
               "1110111" when "00010",
               "1110111" when "00011",
               "1110111" when "00100",
               "1110111" when "00101",
               "1110111" when "00110",
               "1110111" when "00111",
               "1110111" when "01000",
               "XXXXXXX" when others;
   end behaviour;