vlib rtl_work
vmap work rtl_work

vcom -93 -work work {../../list_09_05_06_timer_CORRIGIDO_50mhz.vhd}

vsim work.timer(single_clock_arch)

add wave -position insertpoint sim:/timer/*

radix -unsigned

force -freeze sim:/timer/clk 0 0
force -freeze sim:/timer/reset 1 0
run

force -freeze sim:/timer/reset 0 0
run

force -freeze sim:/timer/r_reg 49999999 0
force -freeze sim:/timer/s_reg 58 0
force -freeze sim:/timer/m_reg 58 0
run

noforce sim:/timer/r_reg
noforce sim:/timer/s_reg
noforce sim:/timer/m_reg

force -freeze sim:/timer/clk 1 0
run
force -freeze sim:/timer/clk 0 0
run

force -freeze sim:/timer/r_reg 49999999 0
run

noforce sim:/timer/r_reg

force -freeze sim:/timer/clk 1 0
run
force -freeze sim:/timer/clk 0 0
run




































