-------------------------
-- File: gray2bin.vhd  --
-------------------------
entity gray2bin is
	generic (N : natural := 4 );
	port
	(
		b  : buffer bit_vector(N-1 downto 0);
		g  : in bit_vector(N-1 downto 0)
	);
end entity;

architecture ifsc_v3 of gray2bin is
begin
	b(N-1) <= g(N-1);

label1:
	for k in N-2 downto 0 generate
		b(k) <= g(k) XOR b(k+1);
	end generate;

end architecture;