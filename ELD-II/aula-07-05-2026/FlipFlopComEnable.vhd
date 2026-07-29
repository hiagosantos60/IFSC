-- Implementar um Flip Flop sensível à borda de subida com reset assíncrono e enable.

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity FlipFlopComEnable is
	port
	(
		clk: in std_logic;
        d: in std_logic;
        q: out std_logic;
        rst: in std_logic;
        enable: in std_logic
	);
end FlipFlopComEnable;

-- IMPLEMENTACAO DE FLIPFLOP D SENSIVEL A BORDA DE SUBIDA COM ENABLE E RESET ASSINCRONO
-- ESSA NAO Eh UMA IMPLEMENTACAO CORRETA PARA A DISCIPLINA
architecture implementacao_v1 of FlipFlopComEnable is
    signal estadoAtual : std_logic;
begin
    process(clk, rst)
    begin
        if rst = '1' then
            estadoAtual <= '0';
        elsif rising_edge(clk) then
            if enable = '1' then
                estadoAtual <= d;
            else
                estadoAtual <= estadoAtual; 
            end if; 
        end if; 
    end process;

    q <= estadoAtual;

end implementacao_v1;

configuration cfg of FlipFlopComEnable is
    for implementacao_v1 end for;
end cfg;
