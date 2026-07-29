-- MOD10 COUNTER IMPLEMENTATION 

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ContadorDecimal is
    port(
        clk, reset : in std_logic;
        q          : out std_logic_vector(3 downto 0)
    );
end ContadorDecimal;

architecture two_seg_arch of ContadorDecimal is
    constant TEN : integer := 10;

    signal r_reg  : unsigned(3 downto 0);
    signal r_next : unsigned(3 downto 0);

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
    r_next <= (others => '0') when r_reg = (TEN - 1) else
              r_reg + 1;

    -- output logic
    q <= std_logic_vector(r_reg);

end two_seg_arch;