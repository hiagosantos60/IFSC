vlib rtl_work
vmap work rtl_work
vcom -93 -work work {/home/hiago.s2006/eld-II/aula-12-05-2026/ShiftRightRegister.vhd}
vsim work.shiftrightregister(two_seg_arch)

add wave -position insertpoint  \
sim:/shiftrightregister/clk \
sim:/shiftrightregister/reset \
sim:/shiftrightregister/d \
sim:/shiftrightregister/q \
sim:/shiftrightregister/r_reg \
sim:/shiftrightregister/r_next

force -freeze sim:/shiftrightregister/reset 1 0
force -freeze sim:/shiftrightregister/clk 1 0
force -freeze sim:/shiftrightregister/d 1 0
run

force -freeze sim:/shiftrightregister/reset 0 0
force -freeze sim:/shiftrightregister/clk 0 0
run

force -freeze sim:/shiftrightregister/clk 1 0
run

force -freeze sim:/shiftrightregister/clk 0 0
run

force -freeze sim:/shiftrightregister/clk 1 0
run

force -freeze sim:/shiftrightregister/d 0 0
force -freeze sim:/shiftrightregister/clk 0 0
run

force -freeze sim:/shiftrightregister/clk 1 0
run

force -freeze sim:/shiftrightregister/clk 0 0
run

force -freeze sim:/shiftrightregister/clk 1 0
run
