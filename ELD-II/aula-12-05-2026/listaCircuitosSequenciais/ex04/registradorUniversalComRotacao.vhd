library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity registradorUniversalComRotacao is
	port
	(
		clk, reset: in STD_LOGIC;
        d: in STD_LOGIC;
        control: in STD_LOGIC_VECTOR(2 downto 0); -- apenas 4 opções de ação
        d_to_right: in STD_LOGIC;
        d_to_left: in STD_LOGIC;
        palavra: in STD_LOGIC_VECTOR(3 downto 0); -- palavra de 4 bits
        q: out STD_LOGIC_VECTOR(3 downto 0)
	);
end registradorUniversalComRotacao;

architecture ex_04 of registradorUniversalComRotacao is
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
            when "000" => r_next <= r_reg; -- para
            when "001" => r_next <= d_to_right & r_reg(3 downto 1); -- deslocar para direita
            when "100" => r_next <= r_reg(2 downto 0) & d_to_left; -- deslocar para esquerda
            
            when "110" => r_next <= r_reg(0) & r_reg(3 downto 1); -- rotacao para direita
            when "011" => r_next <= r_reg(2 downto 0) & r_reg(3); -- rotacao para esquerda 

            when "111" => r_next <= palavra; -- pausar
            when others => r_next <= r_reg;
        end case;
    end process;

    q <= r_reg;
end ex_04;