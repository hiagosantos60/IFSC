
vlib rtl_work
vmap work rtl_work
vmap work rtl_work 

vcom -93 -work work {../../list_09_05_06_timer_CORRIGIDO_50mhz.vhd}

vsim work.timer(multi_clock_arch)

