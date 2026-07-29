library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity registradorUniversal is
	port
	(
		clk, reset: in STD_LOGIC;
        d: in STD_LOGIC;
        control: in STD_LOGIC_VECTOR(1 downto 0); -- apenas 4 opções de ação
        d_to_right: in STD_LOGIC;
        d_to_left: in STD_LOGIC;
        palavra: in STD_LOGIC_VECTOR(3 downto 0); -- palavra de 3 bits
        q: out STD_LOGIC_VECTOR(3 downto 0)
	);
end registradorUniversal;

-- 00 para
-- 10 deslocar esquerda
-- 01 deslocar direita
-- 11 pausar

architecture ex_01 of registradorUniversal is
    signal r_reg  : std_logic_vector(3 downto 0);
    signal r_next : std_logic_vector(3 downto 0);
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

    process (control, r_reg, palavra, d_to_left, d_to_right)
    begin
        case control is 
            when "00" => r_next <= r_reg;
            when "01" => r_next <= d_to_right & r_reg(3 downto 1); -- concatena para direita
            when "10" => r_next <= r_reg(2 downto 0) & d_to_left; -- concatena para a esquerda
            when "11" => r_next <= palavra;
            when others => r_next <= r_reg;
        end case;
    end process;

    q <= r_reg;
end ex_01;



configuration ex_01 of registradorUniversal is 
    for ex_01 end for;
end configuration;