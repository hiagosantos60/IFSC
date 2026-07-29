library ieee;
use ieee.std_logic_1164.all;

entity bcd2ssd is
  port (
    BCD : in std_logic_vector (3 downto 0);
    SSD : out std_logic_vector (6 downto 0)
  );

end entity;

architecture arch of bcd2ssd is
begin

  with BCD select
    SSD <= "1000000" when "0000",
    "1111001" when "0001",
    "0100100" when "0010",
    "0110000" when "0011",
    "0011001" when "0100",
    "0010010" when "0101",
    "0000011" when "0110",
    "1111000" when "0111",
    "0000000" when "1000",
    "0011000" when "1001",
    "0111111" when others;
end arch;