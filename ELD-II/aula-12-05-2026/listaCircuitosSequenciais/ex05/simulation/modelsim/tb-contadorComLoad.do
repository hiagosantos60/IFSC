vlib rtl_work
vmap work rtl_work
vcom -93 -work work {/home/hiago.s2006/eld-II/aula-12-05-2026/listaCircuitosSequenciais/ex05/contadorBinarioComLoad.vhd}
vsim work.contadorbinariocomload
add wave -position insertpoint sim:/contadorbinariocomload/clk sim:/contadorbinariocomload/rst sim:/contadorbinariocomload/up sim:/contadorbinariocomload/load sim:/contadorbinariocomload/load_enable sim:/contadorbinariocomload/q
force -freeze sim:/contadorbinariocomload/rst 1 0
force -freeze sim:/contadorbinariocomload/clk 0 0
run
force -freeze sim:/contadorbinariocomload/clk 1 0
run
force -freeze sim:/contadorbinariocomload/clk 0 0
force -freeze sim:/contadorbinariocomload/rst 0 0
run
force -freeze sim:/contadorbinariocomload/load 00001010 0
force -freeze sim:/contadorbinariocomload/load_enable 1 0
force -freeze sim:/contadorbinariocomload/clk 1 0
run
force -freeze sim:/contadorbinariocomload/clk 0 0
run
force -freeze sim:/contadorbinariocomload/load_enable 0 0
force -freeze sim:/contadorbinariocomload/up 1 0
force -freeze sim:/contadorbinariocomload/clk 1 0
run
force -freeze sim:/contadorbinariocomload/clk 0 0
run
force -freeze sim:/contadorbinariocomload/up 0 0
force -freeze sim:/contadorbinariocomload/clk 1 0
run
force -freeze sim:/contadorbinariocomload/clk 0 0
run