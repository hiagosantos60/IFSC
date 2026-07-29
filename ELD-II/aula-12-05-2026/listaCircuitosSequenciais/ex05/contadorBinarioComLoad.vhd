library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity contadorBinarioComLoad is
    port
    (
        clk, rst : in STD_LOGIC;
        up       : in STD_LOGIC;
        q        : out STD_LOGIC_VECTOR(7 downto 0);
        load	 : in STD_LOGIC_VECTOR(7 downto 0); -- acrecentado
        load_enable: in STD_LOGIC
    );
end contadorBinarioComLoad;

architecture ex_03 of contadorBinarioComLoad is
    signal r_reg  : unsigned(7 downto 0);
    signal r_next : unsigned(7 downto 0);
begin

    -- flipflop d
    process (clk, rst)
    begin
        if (rst = '1') then
            r_reg <= (others => '0');
        elsif (rising_edge(clk)) then
            r_reg <= r_next;
        end if;
    end process;

    -- next state logic
    process (up, r_reg, load_enable, load)
    begin
        if (load_enable = '1') then -- acrecentado
            r_next <= unsigned(load); 
        elsif (up = '1') then
            r_next <= r_reg + 1;      
        else
            r_next <= r_reg - 1;      
        end if;
    end process;
    q <= std_logic_vector(r_reg);

end ex_03;
