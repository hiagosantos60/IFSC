vlib rtl_work
vmap work rtl_work 

vcom -93 -work work {../..contadorBinario.vhd}

vsim work.contadorbinario(ex_03)

add wave -position insertpoint  \
sim:/contadorbinario/clk \
sim:/contadorbinario/rst \
sim:/contadorbinario/up \
sim:/contadorbinario/q \
sim:/contadorbinario/r_reg \
sim:/contadorbinario/r_next

# INICIALIZANDO COM RESET
force -freeze sim:/contadorbinario/rst 1
force -freeze sim:/contadorbinario/up 1
force -freeze sim:/contadorbinario/clk 0
run 

# TIRA O RESET
force -freeze sim:/contadorbinario/rst 0
run 

# PRIMEIRO PULSO COMEÇA A CONTAGEM
force -freeze sim:/contadorbinario/clk 1
run 
force -freeze sim:/contadorbinario/clk 0
run 

# SEGUNDO PULSO 
force -freeze sim:/contadorbinario/clk 1
run 
force -freeze sim:/contadorbinario/clk 0
run 

# TERCEIRO PULSO
force -freeze sim:/contadorbinario/clk 1
run 
force -freeze sim:/contadorbinario/clk 0
run 

# MUDA CONTAGEM
force -freeze sim:/contadorbinario/up 0
run 

# QUARTO PULSO 
force -freeze sim:/contadorbinario/clk 1
run 
force -freeze sim:/contadorbinario/clk 0
run 

# QUINTO PULSO
force -freeze sim:/contadorbinario/clk 1
run 
force -freeze sim:/contadorbinario/clk 0
run 

# SEXTO PULSO
force -freeze sim:/contadorbinario/clk 1
run 
force -freeze sim:/contadorbinario/clk 0
run 

# SETIMO PULSO
force -freeze sim:/contadorbinario/clk 1
run 
force -freeze sim:/contadorbinario/clk 0
run 

# RESET DO SISTEMA
force -freeze sim:/contadorbinario/rst 1
run 
