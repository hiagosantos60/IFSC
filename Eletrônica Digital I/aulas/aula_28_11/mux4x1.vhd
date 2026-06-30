entity mux4x1 is
	port
	(
	   X: in  bit_vector (3 downto 0);
	-- Quando X é declarado como bit_vector (3 downto 0)
	-- ordem dos bits | X(3) | X(2) | X(1) | X(0) |
	-- X(0) é o bit mais a direita do vetor X, X(3) é o bit mais a esquerda do vetor X.

	-- X: in  bit_vector (0 to 3);
	-- Se X é declarado como bit_vector (0 to 3)
	-- ordem dos bits | X(0) | X(1) | X(2) | X(3) |
	-- X(3) é o bit mais a direita do vetor X, X(0) é o bit mais a esquerda do vetor X.
	   Sel : in bit_vector (1 downto 0);
	   Y : out bit
	);
end entity;

-- Implementação com lógica pura
architecture v_logica_pura of mux4x1 is
begin
 Y <= (X(0) and not Sel(1) and not Sel(0)) or
      (X(1) and not Sel(1) and 	  Sel(0)) or
		(X(2) and 	  Sel(1) and not Sel(0)) or
      (X(3) and 	  Sel(1) and 	  Sel(0));

end architecture;

-- Implementação com WHEN ELSE
architecture v_when_else of mux4x1 is
begin
		Y <= X(0) when Sel = "00" else
			  X(1) when Sel = "01" else
			  X(2) when Sel = "10" else
			  X(3);
end architecture;

-- Implementação com WITH SELECT
architecture v_with_select of mux4x1 is
begin
with Sel select
		Y <= X(0) when "00",    -- note o uso da ,
			  X(1) when "01",
			  X(2) when "10",
			  X(3) when others;  -- note o uso de others, para todos os demais valores.  
									   -- Não pode ser substituido por "11" mesmo que o signal seja bit_vector.
end architecture;


configuration cfg_ifsc of mux4x1 is
	for v_logica_pura end for;
--	for v_when_else end for;
--	for v_with_select end for;
end configuration;
--
--#file_name: tb_mux4x1.do
-- arquivo de testes das estruturas, mudar de acordo com qual quer testar.
--
--#preparando o simulador
--vdel -lib rtl_work -all
--vlib rtl_work
--vmap work rtl_work
--
--#vcom -93 -work work {/home/moecke/ELD1/ANO2024.2/Aula26/mux4x1.vhd}
--# substitua o caminho absoluto pelo relativo ../../
--vcom -93 -work work {../../mux4x1.vhd}
--
--#abra o simulador na entity mux4x1 na arquitetura v_logica_pura
--vsim work.mux4x1(v_logica_pura)
--#vsim work.mux4x1(v_when_else)
--#vsim work.mux4x1(v_with_select)
--
--#adicioneos sinais a aba wave
--add wave -position end  sim:/mux4x1/Sel
--add wave -position end  sim:/mux4x1/X
--add wave -position end  sim:/mux4x1/Y
--
--#definindo varios valores de um estimulo  pares (valor instante_de_tempo) separados por virgula
--force -freeze sim:/mux4x1/X 0101 0, 1100 100, 0011 200, 1010 300, 1111 400, 0000 500
--
--#definindo varios valores de um estimulo  pares (valor instante_de_tempo) separados por virgula, e o periodo de repetição 
--# Sel0 começa em 1, depois de 25ps muda para 0 e o ciclo é repetido a cada 50ps. 
--force -freeze sim:/mux4x1/Sel(0) 1 0, 0 {25 ps} -r 50
--# Sel1 começa em 1, depois de 50ps muda para 0 e o ciclo é repetido a cada 100ps. 
--force -freeze sim:/mux4x1/Sel(1) 1 0, 0 {50 ps} -r 100
--
--# Execução da simulação. run ou run tempo
--# Se não tiver unidade é ps (pico segundos) 
--# fs             => femto segundos
--# ps = 1000 fs;  => pico segundos
--# ns = 1000 ps;  => nano segundos
--# us = 1000 ns;  => micro segundos
--# ms = 1000 us;  => mili segundos
--# sec = 1000 ms; => segundos
--# min = 60 sec;  => minutos
--# hr = 60 min;   => horas
--run 600
