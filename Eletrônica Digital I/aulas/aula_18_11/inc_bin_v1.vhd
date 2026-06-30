-------------------------
-- File: inc_bin.vhd  --
-------------------------

entity inc_bin is
	generic (N : natural := 4 );
	port
	(
		bin_in  : in integer range 0 to 15;
		bin_out : out integer range 0 to 15
	);
end entity;

architecture ifsc_v1 of inc_bin is
begin
	
	bin_out <= bin_in + 1;

end architecture;