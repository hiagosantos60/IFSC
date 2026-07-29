-- BINARY COUNTER WITH MAX PULSE IMPLEMENTATION

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity ContadorBinario is
	port
	(
		clk,reset: in std_logic;
		max_pulse: out std_logic;
		q: out std_logic_vector(3 downto 0)
	);
end ContadorBinario;


architecture exemplo_v1 of ContadorBinario is
	signal r_reg:  unsigned(3 downto 0);
   signal r_next: unsigned(3 downto 0);
begin
	-- register
    process(clk, reset)
    begin
        if (reset = '1') then
            r_reg <= (others => '0');
        elsif (clk'event and clk = '1') then
            r_reg <= r_next;
        end if;
    end process;

    -- next-state logic
    r_next <= r_reg + 1;

    -- output logic
    q <= std_logic_vector(r_reg);
    
    max_pulse <= '1' when r_reg = "1111" else  '0';
	 
end exemplo_v1;