vlib rtl_work
vmap work rtl_work
vcom -93 -work work {../../top_timer_de2_115.vhd}
vsim work.timer

add wave -position insertpoint sim:/timer/*

force -freeze sim:/timer/reset 1 0
force -freeze sim:/timer/clk 0 0
run
force -freeze sim:/timer/clk 1 0
run
force -freeze sim:/timer/clk 0 0
run
force -freeze sim:/timer/reset 0 0
run

force -freeze sim:/timer/h_reg 10#0 0
force -freeze sim:/timer/m_reg 10#0 0
force -freeze sim:/timer/s_reg 10#0 0
force -freeze sim:/timer/r_reg 10#1999 0   
run
noforce sim:/timer/h_reg
noforce sim:/timer/m_reg
noforce sim:/timer/s_reg
noforce sim:/timer/r_reg

force -freeze sim:/timer/clk 1 0
run
force -freeze sim:/timer/clk 0 0
run

# virada de Minuto (00:00:59 -> 00:01:00)
force -freeze sim:/timer/h_reg 10#0 0
force -freeze sim:/timer/m_reg 10#0 0
force -freeze sim:/timer/s_reg 10#59 0  
force -freeze sim:/timer/r_reg 10#1999 0 
run
noforce sim:/timer/h_reg
noforce sim:/timer/m_reg
noforce sim:/timer/s_reg
noforce sim:/timer/r_reg

force -freeze sim:/timer/clk 1 0
run
force -freeze sim:/timer/clk 0 0
run

# Virada de Hora (00:59:59 -> 01:00:00) 
force -freeze sim:/timer/h_reg 10#0 0
force -freeze sim:/timer/m_reg 10#59 0
force -freeze sim:/timer/s_reg 10#59 0
force -freeze sim:/timer/r_reg 10#1999 0 
run
noforce sim:/timer/h_reg
noforce sim:/timer/m_reg
noforce sim:/timer/s_reg
noforce sim:/timer/r_reg

force -freeze sim:/timer/clk 1 0
run
force -freeze sim:/timer/clk 0 0
run

# Virada de Dia (23:59:59 -> 00:00:00) 
force -freeze sim:/timer/h_reg 10#23 0
force -freeze sim:/timer/m_reg 10#59 0
force -freeze sim:/timer/s_reg 10#59 0
force -freeze sim:/timer/r_reg 10#1999 0 
run
noforce sim:/timer/h_reg
noforce sim:/timer/m_reg
noforce sim:/timer/s_reg
noforce sim:/timer/r_reg

force -freeze sim:/timer/clk 1 0
run
force -freeze sim:/timer/clk 0 0
run


# incremento de segundos com uma hora > 0 (Ex: 10:15:05 -> 10:15:06) ---
force -freeze sim:/timer/h_reg 10#10 0
force -freeze sim:/timer/m_reg 10#15 0
force -freeze sim:/timer/s_reg 10#5 0
force -freeze sim:/timer/r_reg 10#1999 0 
run
noforce sim:/timer/h_reg
noforce sim:/timer/m_reg
noforce sim:/timer/s_reg
noforce sim:/timer/r_reg

# bate o clock para dar 1 segundo
force -freeze sim:/timer/clk 1 0
run
force -freeze sim:/timer/clk 0 0
run

# bate o clock mais uma vez com r_reg em 0 (ciclo normal sem estourar o timer)
# Aqui a hora e minuto não podem mudar.
force -freeze sim:/timer/clk 1 0
run
force -freeze sim:/timer/clk 0 0
run

# Virada de Minuto com uma hora > 0 (Ex: 14:10:59 -> 14:11:00)
# Objetivo: O minuto deve incrementar, o segundo zerar, mas a HORA deve ficar intacta.
force -freeze sim:/timer/h_reg 10#14 0
force -freeze sim:/timer/m_reg 10#10 0
force -freeze sim:/timer/s_reg 10#59 0
force -freeze sim:/timer/r_reg 10#1999 0 
run
noforce sim:/timer/h_reg
noforce sim:/timer/m_reg
noforce sim:/timer/s_reg
noforce sim:/timer/r_reg

# Bate o clock para virar o minuto
force -freeze sim:/timer/clk 1 0
run
force -freeze sim:/timer/clk 0 0
run

# Bate o clock mais uma vez no ciclo normal (s_reg = 0, r_reg = 0)
# A hora não pode ir para 15 aqui.
force -freeze sim:/timer/clk 1 0
run
force -freeze sim:/timer/clk 0 0
run
