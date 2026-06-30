-------------------------
-- File: bin2gray_v3.vhd  --
-------------------------
entity bin2gray_v3 is
	generic (N : natural := 4 );
	port
	(
		b  : in bit_vector(N-1 downto 0);
		g  : out bit_vector(N-1 downto 0)
	);
end entity;

architecture ifsc_v3 of bin2gray_v3 is
begin
	g(N-1) <= b(N-1);

	label1:
	for k in N-2 downto 0 generate
		g(k) <= b(k) XOR b(k+1);
	end generate;

end architecture;