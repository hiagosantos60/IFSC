-- implementacao dos multiplexadores 4x1 para revisao 
-- disponivel no registro da disciplina ELD I do professor marcos moecke

library ieee;
use IEEE.STD_LOGIC_1164.all;

entity multiplexadores is
	port
	(
	   X: in  bit_vector (3 downto 0);
	   Sel : in bit_vector (1 downto 0);
	   Y : out bit
	);
end entity;

architecture v_logica_pura of multiplexadores is
begin
 Y <= (X(0) and (not Sel(1)) and (not Sel(0))) or
      (X(1) and (not Sel(1)) and Sel(0)) or
      (x(2) and Sel(1) and not (Sel(0))) or
		(x(3) and Sel(1) and Sel(0));
end architecture;

-- IMPLEMENTACAO WHEN ELSE
architecture v_WHEN_ELSE of multiplexadores is
begin
 Y <= X(0) when Sel = "00" else
      X(1) when Sel = "01" else
      X(2) when Sel = "10" else
      X(3);
end architecture;

-- IMPLEMENTACAO WITH SELECT
architecture v_WITH_SELECT of multiplexadores is
begin
 with Sel select
 Y <= X(0) when "00",    
      X(1) when "01",
      X(2) when "10",
      X(3) when others;  -- note o uso de others, para todos os demais valores.  
                         -- Não pode ser substituido por "11" mesmo que o signal seja bit_vector.
end architecture;

configuration cfg_ifsc_v1 of multiplexadores is
	for v_logica_pura end for;
	for v_WHEN_ELSE end for;
	for v_WITH_SELECT end for;
end configuration;