-------------------------
-- File: inc_bin_v2.vhd  --
-------------------------
library ieee;
use ieee.numeric_std.all;

entity inc_bin_v2 is
	generic (N : natural := 4 );
	port
	(
		bin_in  : in unsigned(3 downto 0);
		bin_out : out unsigned(3 downto 0)
	);
end entity;

architecture ifsc_v1 of inc_bin_v2 is
begin
	
	bin_out <= bin_in + 1;

end architecture;