
# Iniciando a simulacao
vsim work.top_timer_de2_115

# Adicionando os sinais de clock e reset
add wave -position insertpoint  \
sim:/top_timer_de2_115/CLOCK_50 \
sim:/top_timer_de2_115/KEY 

# Adicionando os sinais com "radix" unsigned
add wave -position insertpoint -radix unsigned \
sim:/top_timer_de2_115/t0/load \
sim:/top_timer_de2_115/t0/sec_i \
sim:/top_timer_de2_115/t0/min_i \
sim:/top_timer_de2_115/t0/hour_i \
sim:/top_timer_de2_115/t0/r_reg \
sim:/top_timer_de2_115/t0/s_reg \
sim:/top_timer_de2_115/t0/m_reg \
sim:/top_timer_de2_115/t0/h_reg 

# Criando clock e forçando reset
force -freeze sim:/top_timer_de2_115/CLOCK_50 1 0, 0 {10000 ps} -r 20ns
force -freeze sim:/top_timer_de2_115/KEY 0 0 

force -freeze sim:/top_timer_de2_115/t0/load 0 0 
force -freeze sim:/top_timer_de2_115/t0/sec_i 10#30 0
force -freeze sim:/top_timer_de2_115/t0/min_i 10#55 0
force -freeze sim:/top_timer_de2_115/t0/hour_i 10#17 0

run 40ns
force -freeze sim:/top_timer_de2_115/KEY 1 0 
run 40ns


# Forcando alguns valores de borda para verificar o funcionamento
force -freeze sim:/top_timer_de2_115/t0/r_reg 10#49999999 0 -cancel 20ns
run 200ns

force -freeze sim:/top_timer_de2_115/t0/r_reg 10#49999999 0 -cancel 20ns
force -freeze sim:/top_timer_de2_115/t0/s_reg 10#59 0 -cancel 20ns
run 200ns

force -freeze sim:/top_timer_de2_115/t0/r_reg 10#49999999 0 -cancel 20ns
force -freeze sim:/top_timer_de2_115/t0/s_reg 10#59 0 -cancel 20ns
force -freeze sim:/top_timer_de2_115/t0/m_reg 10#59 0 -cancel 20ns
run 200ns

force -freeze sim:/top_timer_de2_115/t0/r_reg 10#49999999 0 -cancel 20ns
force -freeze sim:/top_timer_de2_115/t0/s_reg 10#59 0 -cancel 20ns
force -freeze sim:/top_timer_de2_115/t0/m_reg 10#59 0 -cancel 20ns
force -freeze sim:/top_timer_de2_115/t0/h_reg 10#23 0 -cancel 20ns
run 200ns

force -freeze sim:/top_timer_de2_115/t0/load 1 0 
run 200ns

force -freeze sim:/top_timer_de2_115/t0/load 0 0 
run 200ns



