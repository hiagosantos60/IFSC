
vlib rtl_work
vmap work rtl_work 
vcom -93 -work work {../../contadorSequencial.vhd}
vsim work.contadorsequencial(ex_02)
add wave -position insertpoint  \
sim:/contadorsequencial/clk \
sim:/contadorsequencial/rst \
sim:/contadorsequencial/q \
sim:/contadorsequencial/q_contador \
sim:/contadorsequencial/d_contador


force -freeze sim:/contadorsequencial/rst 1 0
force -freeze sim:/contadorsequencial/clk 0 0
run

# Passo 2: Libera o Reset (Contador em "000")
force -freeze sim:/contadorsequencial/rst 0 0
run

# Passo 3: 1º Pulso de Clock -> Deve ir para "011"
force -freeze sim:/contadorsequencial/clk 1 0
run 
force -freeze sim:/contadorsequencial/clk 0 0
run

# Passo 4: 2º Pulso de Clock -> Deve ir para "100"
force -freeze sim:/contadorsequencial/clk 1 0
run 
force -freeze sim:/contadorsequencial/clk 0 0
run

# Passo 5: 3º Pulso de Clock -> Deve ir para "101"
force -freeze sim:/contadorsequencial/clk 1 0
run 
force -freeze sim:/contadorsequencial/clk 0 0
run 

# Passo 6: 4º Pulso de Clock -> Deve ir para "111"
force -freeze sim:/contadorsequencial/clk 1 0
run 
force -freeze sim:/contadorsequencial/clk 0 0
run 

# Passo 7: 5º Pulso de Clock -> Deve resetar a sequência voltando para "000"
force -freeze sim:/contadorsequencial/clk 1 0
run 
force -freeze sim:/contadorsequencial/clk 0 0
run 

# Passo 8: Teste do Reset Assíncrono no meio do caminho
# Dá mais um clock para ele ir para "011" novamente
force -freeze sim:/contadorsequencial/clk 1 0
run 
force -freeze sim:/contadorsequencial/clk 0 0
run 

# Força o botão de reset (Deve ir para "000" imediatamente, sem precisar de clock)
force -freeze sim:/contadorsequencial/rst 1 0
run 
