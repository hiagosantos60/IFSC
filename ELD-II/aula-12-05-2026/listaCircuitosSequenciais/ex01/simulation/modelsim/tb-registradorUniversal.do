vlib rtl_work
vmap work rtl_work 
vcom -93 -work work {../../registradorUniversal.vhd}
vsim work.registradoruniversal(ex_01)

add wave -position insertpoint  \
sim:/registradoruniversal/clk \
sim:/registradoruniversal/reset \
sim:/registradoruniversal/d \
sim:/registradoruniversal/control \
sim:/registradoruniversal/d_to_right \
sim:/registradoruniversal/d_to_left \
sim:/registradoruniversal/palavra \
sim:/registradoruniversal/q \
sim:/registradoruniversal/r_reg \
sim:/registradoruniversal/r_next

# RESET
force -freeze sim:/registradoruniversal/reset 1 0
force -freeze sim:/registradoruniversal/control 00 0
force -freeze sim:/registradoruniversal/palavra 0000 0
force -freeze sim:/registradoruniversal/d_to_right 0 0
force -freeze sim:/registradoruniversal/d_to_left 0 0
force -freeze sim:/registradoruniversal/clk 0 0
run
force -freeze sim:/registradoruniversal/clk 1 0
run
force -freeze sim:/registradoruniversal/clk 0 0
run

# INSERINDO PALAVRA
force -freeze sim:/registradoruniversal/reset 0 0
force -freeze sim:/registradoruniversal/control 11 0
force -freeze sim:/registradoruniversal/palavra 1010 0
force -freeze sim:/registradoruniversal/d_to_right 0 0
force -freeze sim:/registradoruniversal/d_to_left 0 0
force -freeze sim:/registradoruniversal/clk 1 0
run
force -freeze sim:/registradoruniversal/clk 0 0
run

# DESLOCAR PARA DIREITA BIT 1
force -freeze sim:/registradoruniversal/reset 0 0
force -freeze sim:/registradoruniversal/control 01 0
force -freeze sim:/registradoruniversal/palavra 1010 0
force -freeze sim:/registradoruniversal/d_to_right 1 0
force -freeze sim:/registradoruniversal/d_to_left 0 0
force -freeze sim:/registradoruniversal/clk 1 0
run
force -freeze sim:/registradoruniversal/clk 0 0
run

# DESLOCAR PARA DIREITA 0
force -freeze sim:/registradoruniversal/reset 0 0
force -freeze sim:/registradoruniversal/control 01 0
force -freeze sim:/registradoruniversal/palavra 1010 0
force -freeze sim:/registradoruniversal/d_to_right 0 0
force -freeze sim:/registradoruniversal/d_to_left 0 0
force -freeze sim:/registradoruniversal/clk 1 0
run
force -freeze sim:/registradoruniversal/clk 0 0
run

# DESLOCAR PARA ESQUERDA BIT 1
force -freeze sim:/registradoruniversal/reset 0 0
force -freeze sim:/registradoruniversal/control 10 0
force -freeze sim:/registradoruniversal/palavra 1010 0
force -freeze sim:/registradoruniversal/d_to_right 0 0
force -freeze sim:/registradoruniversal/d_to_left 1 0
force -freeze sim:/registradoruniversal/clk 1 0
run
force -freeze sim:/registradoruniversal/clk 0 0
run

# DESLOCAR PARA DIREITA BIT 0
force -freeze sim:/registradoruniversal/reset 0 0
force -freeze sim:/registradoruniversal/control 10 0
force -freeze sim:/registradoruniversal/palavra 1010 0
force -freeze sim:/registradoruniversal/d_to_right 0 0
force -freeze sim:/registradoruniversal/d_to_left 0 0
force -freeze sim:/registradoruniversal/clk 1 0
run
force -freeze sim:/registradoruniversal/clk 0 0
run

# PAUSAR LEITURA, IGNORA AS ENTRADAS
force -freeze sim:/registradoruniversal/reset 0 0
force -freeze sim:/registradoruniversal/control 00 0
force -freeze sim:/registradoruniversal/palavra 1111 0
force -freeze sim:/registradoruniversal/d_to_right 1 0
force -freeze sim:/registradoruniversal/d_to_left 1 0
force -freeze sim:/registradoruniversal/clk 1 0
run
force -freeze sim:/registradoruniversal/clk 0 0
run

