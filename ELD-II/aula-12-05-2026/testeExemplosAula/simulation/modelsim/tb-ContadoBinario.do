vlib rtl_work
vmap work rtl_work
vcom -93 -work work {/home/hiago.s2006/eld-II/aula-12-05-2026/ContadorBinario.vhd}
vsim work.contadorbinario(exemplo_v1)

add wave -position insertpoint  \
sim:/contadorbinario/clk \
sim:/contadorbinario/reset \
sim:/contadorbinario/max_pulse \
sim:/contadorbinario/q \
sim:/contadorbinario/r_reg \
sim:/contadorbinario/r_next

force -freeze sim:/contadorbinario/reset 1 0
force -freeze sim:/contadorbinario/clk 1 0
run
force -freeze sim:/contadorbinario/clk 0 0
force -freeze sim:/contadorbinario/reset 0 0
run
force -freeze sim:/contadorbinario/clk 1 0
run
force -freeze sim:/contadorbinario/clk 0 0
run
force -freeze sim:/contadorbinario/clk 1 0
run
force -freeze sim:/contadorbinario/clk 0 0
run
force -freeze sim:/contadorbinario/clk 1 0
run
force -freeze sim:/contadorbinario/clk 0 0
run
force -freeze sim:/contadorbinario/clk 1 0
run
force -freeze sim:/contadorbinario/clk 0 0
run
force -freeze sim:/contadorbinario/clk 1 0
run
force -freeze sim:/contadorbinario/clk 0 0
run
force -freeze sim:/contadorbinario/clk 1 0
run
force -freeze sim:/contadorbinario/clk 0 0
run
force -freeze sim:/contadorbinario/clk 1 0
run
force -freeze sim:/contadorbinario/clk 0 0
run
force -freeze sim:/contadorbinario/clk 1 0
run
force -freeze sim:/contadorbinario/clk 0 0
run
force -freeze sim:/contadorbinario/clk 1 0
run
force -freeze sim:/contadorbinario/clk 0 0
run
force -freeze sim:/contadorbinario/clk 1 0
run
force -freeze sim:/contadorbinario/clk 0 0
run
force -freeze sim:/contadorbinario/clk 1 0
run
force -freeze sim:/contadorbinario/clk 0 0
run
force -freeze sim:/contadorbinario/clk 1 0
run
force -freeze sim:/contadorbinario/clk 0 0
run
force -freeze sim:/contadorbinario/clk 1 0
run
force -freeze sim:/contadorbinario/clk 0 0
run
force -freeze sim:/contadorbinario/clk 1 0
run
force -freeze sim:/contadorbinario/clk 0 0
run
force -freeze sim:/contadorbinario/clk 1 0
run
force -freeze sim:/contadorbinario/clk 0 0
run
force -freeze sim:/contadorbinario/clk 1 0
run