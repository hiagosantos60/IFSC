-- A bibliteca std e o pacote standard são autodeclarados, então as linhas abaixo podem ser comentadas com "--"


entity bin2ssd is
    port (
    -- Entradas ABCD do circuito
    A, B, C, D: in bit; 
    -- Saidas para os leds do mostrador de 7 segmentos. Note que o nome a, b, .. g foi mudado para ssd_a, ssd_b, ... ssd_g pois o VHDL é insensível a caixa                            
    ssd_a, ssd_b, ssd_c, ssd_d, ssd_e, ssd_f, ssd_g : out bit
    );
end entity;

architecture ifsc_p1 of bin2ssd is
begin
    -- descreva a expressão lógica obtida para cada uma das saídas no projeto 1;
    -- Por exemplo: se for a = A + C + (B'.D') + (B.D)
    ssd_a <= A or C or (not B and not D) or (B and D);
    
end architecture;

architecture ifsc_p2 of bin2ssd  is
begin
    -- descreva a expressão lógica obtida para cada uma das saídas no projeto 3;
end architecture;

architecture ifsc_p3 of bin2ssd  is
begin
    -- descreva a expressão lógica obtida para cada uma das saídas no projeto 3;
end architecture;

library ieee;
use ieee.numeric_bit.all;
architecture ifsc_p4 of bin2ssd is
    signal ssd: bit_vector(6 downto 0);
    signal bcd_in : bit_vector(3 downto 0);    
begin
    bcd_in <= A & B & C & D;
    with     to_integer(unsigned(bcd_in))  select
        ssd <= "0111111" when 0, 
                 "0000110" when 1,
                 "1011011" when 2,
                 "1001111" when 3,
                 "1100110" when 4,
                 "1101101" when 5,
                 "1111101" when 6,
                 "0000111" when 7,
                 "1111111" when 8,
                 "1101111" when 9,
                 "0000000" when others;
    ssd_a <= ssd(0);
    ssd_b <= ssd(1);
    ssd_c <= ssd(2);
    ssd_d <= ssd(3);
    ssd_e <= ssd(4);
    ssd_f <= ssd(5);
    ssd_g <= ssd(6);

end architecture;

-- A instrução configuration defina para o quartus qual das arquiteturas deve ser associada a entidade bin2ssd;
-- No ModelSim todas arquiteturas ficam disponíveis para simulação.
configuration bin2ssd_cfg of bin2ssd is
    for ifsc_p4 end for;
end configuration;