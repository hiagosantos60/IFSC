
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity blink is
   port(
      clk, reset, en: in std_logic;
		blink	: out std_logic
   );
end blink;

architecture arch of blink is
  signal r_reg: unsigned(25 downto 0);
  signal r_next: unsigned(25 downto 0);
begin
  -- register
  process(clk,reset)
  begin
     if (reset='1') then
        r_reg <= (others=>'0');       
     elsif (clk'event and clk='1') then
        r_reg <= r_next;
     end if;
  end process;
  
  -- next-state logic
  r_next <= (others=>'0') when r_reg=49999999 else
            r_reg + 1;

  blink <= '1' when (en='1' and r_reg > 25000000) else
           '0';
end arch;
