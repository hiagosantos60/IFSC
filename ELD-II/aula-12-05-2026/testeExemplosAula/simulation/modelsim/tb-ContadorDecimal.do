
vlib rtl_work
vmap work rtl_work

vmap work rtl_work 

vcom -93 -work work {/home/hiago.s2006/eld-II/aula-12-05-2026/ContadorDecimal.vhd}

vsim work.contadordecimal(two_seg_arch)

add wave -position insertpoint  \
sim:/contadordecimal/clk \
sim:/contadordecimal/reset \
sim:/contadordecimal/q \
sim:/contadordecimal/r_reg \
sim:/contadordecimal/r_next

vlib rtl_work
vmap work rtl_work

vmap work rtl_work 

vcom -93 -work work {/home/hiago.s2006/eld-II/aula-12-05-2026/ContadorDecimal.vhd}

vsim work.contadordecimal(two_seg_arch)

add wave -position insertpoint  \
sim:/contadordecimal/clk \
sim:/contadordecimal/reset \
sim:/contadordecimal/q \
sim:/contadordecimal/r_reg \
sim:/contadordecimal/r_next

force -freeze sim:/contadordecimal/reset 1 0
force -freeze sim:/contadordecimal/clk 1 0
run
force -freeze sim:/contadordecimal/clk 0 0
force -freeze sim:/contadordecimal/reset 0 0
run
force -freeze sim:/contadordecimal/clk 1 0
run
force -freeze sim:/contadordecimal/clk 0 0
run
force -freeze sim:/contadordecimal/clk 1 0
run
force -freeze sim:/contadordecimal/clk 0 0
run
force -freeze sim:/contadordecimal/clk 1 0
run
force -freeze sim:/contadordecimal/clk 0 0
run
force -freeze sim:/contadordecimal/clk 1 0
run
force -freeze sim:/contadordecimal/clk 0 0
run
force -freeze sim:/contadordecimal/clk 1 0
run
force -freeze sim:/contadordecimal/clk 0 0
run
force -freeze sim:/contadordecimal/clk 1 0
run
force -freeze sim:/contadordecimal/clk 0 0
run
force -freeze sim:/contadordecimal/clk 1 0
run
force -freeze sim:/contadordecimal/clk 0 0
run
force -freeze sim:/contadordecimal/clk 1 0
run
force -freeze sim:/contadordecimal/clk 0 0
run
force -freeze sim:/contadordecimal/clk 1 0
run
force -freeze sim:/contadordecimal/clk 0 0
run
force -freeze sim:/contadordecimal/clk 1 0
run
force -freeze sim:/contadordecimal/clk 0 0
run
force -freeze sim:/contadordecimal/clk 1 0
run
force -freeze sim:/contadordecimal/clk 0 0
run
force -freeze sim:/contadordecimal/clk 1 0
run
force -freeze sim:/contadordecimal/clk 0 0
run
force -freeze sim:/contadordecimal/clk 1 0
run
force -freeze sim:/contadordecimal/clk 0 0
run
force -freeze sim:/contadordecimal/clk 1 0
run
force -freeze sim:/contadordecimal/clk 0 0
run
force -freeze sim:/contadordecimal/clk 1 0
run
force -freeze sim:/contadordecimal/clk 0 0
run
