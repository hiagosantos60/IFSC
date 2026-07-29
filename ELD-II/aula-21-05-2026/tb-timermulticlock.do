vlib rtl_work
vmap work rtl_work

vcom -93 -work work {../../list_09_05_06_timer_CORRIGIDO_50mhz.vhd}

vsim work.timer(multi_clock_arch)

add wave -position insertpoint sim:/timer/*

force -freeze sim:/timer/clk 0 0
force -freeze sim:/timer/reset 1 0
run

force -freeze sim:/timer/reset 0 0
run

force -freeze sim:/timer/clk 1 0
#colocar no ultimo valor de registro de clk e colocar 
force -freeze sim:/timer/r_reg "01011111010111100000111111" 0
#colocar no ultimo segundo
force -freeze sim:/timer/s_reg "111011" 0
run

#tira os valores
noforce sim:/timer/r_reg
noforce sim:/timer/s_reg

force -freeze sim:/timer/clk 0 0
run
force -freeze sim:/timer/clk 1 0
run
force -freeze sim:/timer/clk 0 0
run
force -freeze sim:/timer/clk 1 0
run