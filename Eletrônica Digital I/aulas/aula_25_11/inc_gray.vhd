-------------------------
-- File: inc_gray.vhd  --
-------------------------
-- declaração da biblioteca e pacotes necessários  (library e use)
library ieee;
use ieee.numeric_bit.all;

entity inc_gray is
generic (N : natural := 1000);
    port
    (
        g_in   : in bit_vector(N-1 downto 0);
        g_out  : out bit_vector(N-1 downto 0)
    );
end entity;
architecture ifsc_v1 of inc_gray is
	-- declaração dos sinais internos necessários (signal)
    signal bin   : unsigned(N-1 downto 0);
    signal bin_inc   : unsigned(N-1 downto 0);

begin
	-- Converter a entrada de g_in para b_in
	-- código visto e aula anterior

    label1: 
    for k in N-2 downto 0 generate
        bin(k) <= g_in(k) XOR bin(k+1);
    end generate; 
    bin(N-1) <= g_in(N-1);

    -- Incrementar e binário  b_inc = b_in + 1
    -- ver as opções acima.

    bin_inc <= bin + 1;

    -- Converter a entrada de b_out para g_out
    -- código visto e aula anterior

    label2: 
    for k in N-2 downto 0 generate
        g_out(k) <= bin_inc(k) XOR bin_inc(k+1);
    end generate; 
    g_out(N-1) <= bin_inc(N-1);

end architecture;