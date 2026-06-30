-------------------------
-- File: bin2gray_v1.vhd  --
-------------------------
entity bin2gray_v1 is
	port
	(
		b0, b1, b2, b3  : in bit;
		g0, g1, g2, g3  : out bit
	);
end entity;


architecture ifsc_v1 of bin2gray_v1 is
begin

	g3 <= b3;
	g2 <= b2 XOR b3;
	g1 <= b1 XOR b2;
	g0 <= b0 XOR b1;

end architecture;