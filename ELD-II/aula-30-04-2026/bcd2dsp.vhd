library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity bcd2dsp is
	port
	(
		sw : in std_logic_vector(3 downto 0);
		dsp : out std_logic_vector(6 downto 0)
	);
end bcd2dsp;

architecture implementacao of bcd2dsp is
begin
	process(sw)
	begin
		case sw 	is
			when "0000" => dsp <= "0000001";
			when "0001" => dsp <= "1001111";
			when "0010" => dsp <= "0010010";
			when "0011" => dsp <= "0000110";
			when "0100" => dsp <= "1001100";
			when "0101" => dsp <= "0100100";
			when "0110" => dsp <= "0100000";
			when "0111" => dsp <= "0001111";
			when "1000" => dsp <= "0000000";
			when "1001" => dsp <= "0001100";
			when others => dsp <= "1111111";
		end case;
	end process;
end implementacao;

configuration cfg of bcd2dsp is
	for implementacao end for;
end cfg;


