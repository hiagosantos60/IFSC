library ieee;
use ieee.std_logic_1164.all;

entity demux1x4 is
	port	(
		X	: in  std_logic;
		enable : in std_logic;
		sel	: in  std_logic_vector(1 downto 0);
		Y	: out std_logic_vector(3 downto 0)
	);
end entity;

architecture ifsc_v1 of demux1x4 is
begin
	y(0) <= X and (not sel(1)) and (not sel(0));
	y(1) <= X and (not sel(1)) and (    sel(0));
	y(2) <= X and (	 sel(1)) and (not sel(0));
	y(3) <= X and (	 sel(1)) and (		sel(0));

end architecture;

architecture ifsc_v2 of demux1x4 is
begin

	Y <= 
	"000" & X      when sel = "00" else
	"00" & X & "0" when sel = "01" else
	"0" & X & "00" when sel = "10" else	
	X & "000";
	
end architecture;

architecture ifsc_v3 of demux1x4 is
--A alta impendância é representada por "Z" maiúsculo e não pelo "z" minúsculo.
begin
	
	Y <= 
	"ZZZ" & X      when sel = "00" else
	"ZZ" & X & "Z" when sel = "01" else
	"Z" & X & "ZZ" when sel = "10" else	
	X & "ZZZ"; 

end architecture;

architecture ifsc_v4 of demux1x4 is
	signal Y_temp	: std_logic_vector(3 downto 0);
begin
	
	Y_temp <= 
	"ZZZ" & X      when sel = "00" else
	"ZZ" & X & "Z" when sel = "01" else
	"Z" & X & "ZZ" when sel = "10" else	
	X & "ZZZ"; 
	
	Y <= Y_temp when enable = '1' else "ZZZZ";
end architecture;

architecture ifsc_v5 of demux1x4 is
	signal Y_temp	: std_logic_vector(3 downto 0);	
begin
	with sel select
		Y_temp <= "ZZZ" & X when "00",
					 "ZZ" & X & "Z" when "01";
					 "Z" & X & "ZZ" when "10";
					 X & "ZZZ" when others;
		Y <= Y_temp when enable = '1' else "ZZZZ";
	
configuration demux1x4_cfg of demux1x4 is
	for ifsc_v4 end for;
end configuration;