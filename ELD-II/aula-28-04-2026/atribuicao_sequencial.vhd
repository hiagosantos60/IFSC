
library ieee;
use IEEE.STD_LOGIC_1164.all;
use ieee.numeric_std.all;

entity atribuicao_sequencial is
	port
	(
		a : in std_logic_vector(7 downto 0);
		b : in std_logic_vector(7 downto 0);
		
		gt : out std_logic;
		eq : out std_logic;
		lt : out std_logic
	);
end atribuicao_sequencial;

-- implementacao atribuicao incorreta
architecture atribuicao_incorreta of atribuicao_sequencial is
	signal a_signed, b_signed : signed(7 downto 0);
begin
	a_signed <= signed(a);
	b_signed <= signed(b);

	process (a_signed,b_signed)
	begin
		if (a_signed > b_signed) then
			gt <= '1';
		elsif (a_signed = b_signed) then
			eq <= '1';
		else
			lt <= '1';
		end if;
	end process;
end atribuicao_incorreta;

-- correcao 1 para o codigo acima
architecture atribuicao_correta_v1 of atribuicao_sequencial is
	signal a_signed, b_signed : signed(7 downto 0);
begin
	a_signed <= signed(a);
	b_signed <= signed(b);

	process (a_signed,b_signed)
	begin
		if (a_signed > b_signed) then
			gt <= '1';
			eq <= '0';
			lt <= '0';
		elsif (a_signed = b_signed) then
			gt <= '0';
			eq <= '1';
			lt <= '0';
		else
			gt <= '0';
			eq <= '0';
			lt <= '1';
		end if;
	end process;
end atribuicao_correta_v1;

-- correcao 2 para o codigo acima
architecture atribuicao_correta_v2 of atribuicao_sequencial is
	signal a_signed, b_signed : signed(7 downto 0);
begin
	a_signed <= signed(a);
	b_signed <= signed(b);

	process (a_signed,b_signed)
	begin
		gt <= '0';
		eq <= '0';
		lt <= '0';
	
		if (a_signed > b_signed) then
			gt <= '1';
		elsif (a_signed = b_signed) then
			eq <= '1';
		else
			lt <= '1';
		end if;
	end process;
end atribuicao_correta_v2;

configuration cfg_atribuicoes of atribuicao_sequencial is
	--for atribuicao_incorreta end for;
	--for atribuicao_correta_v1 end for;
	for atribuicao_correta_v2 end for;
end cfg_atribuicoes;


