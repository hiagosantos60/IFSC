library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity hamming_distance is
	generic (
		N: 	natural := 25; 
		M: 	natural := 5); -- M = ceil(log2(N))
	port(
		a, b :	in  std_logic_vector (N-1 downto 0);
		y :	out std_logic_vector (M-1 downto 0));
end entity;

architecture ifsc_arch_gen of hamming_distance is
	signal diff: unsigned (N-1 downto 0);
	signal sum: unsigned (M-1 downto 0);
begin
	diff <= unsigned(a xor b);
	process (diff)
		variable tmp : integer range 0 to N;
	begin	
		tmp := 0;
		for i in diff'range loop
			tmp := tmp + to_integer(unsigned'('0' & diff(i)));
		end loop;
		sum <= to_unsigned(tmp,M);
	end process;
	y <= std_logic_vector(sum);
end architecture;