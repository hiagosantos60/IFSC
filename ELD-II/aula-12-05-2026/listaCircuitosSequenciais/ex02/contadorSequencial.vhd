library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity contadorSequencial is
	port
	(
        clk, rst: in STD_LOGIC;
        q: out STD_LOGIC_VECTOR(2 downto 0)
	);
end contadorSequencial;


architecture ex_02 of contadorSequencial is
    signal q_contador : STD_LOGIC_VECTOR(2 downto 0);
    signal d_contador : STD_LOGIC_VECTOR(2 downto 0);
begin
    process (clk,rst)
    begin
        if (rst = '1') then
            q_contador <= "000";
        elsif (rising_edge(clk)) then
            q_contador <= d_contador; 
        end if;
    end process;

    process (q_contador)
    begin
        case q_contador is
            when "000" => d_contador <= "011";
            when "011" => d_contador <= "100";
            when "100" => d_contador <= "101";
            when "101" => d_contador <= "111";
            when others => d_contador <= "000"; 
        end case;               
    end process;

    q <= q_contador;

end ex_02;

configuration cfg of contadorSequencial is 
	for ex_02 end for;
end;