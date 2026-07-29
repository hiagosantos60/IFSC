
vlib rtl_work
vmap work rtl_work

vcom -93 -work work {/../../registradorUniversalComRotacao.vhd}

vsim work.registradoruniversalcomrotacao

add wave -position insertpoint  \
sim:/registradoruniversalcomrotacao/clk \
sim:/registradoruniversalcomrotacao/reset \
sim:/registradoruniversalcomrotacao/d \
sim:/registradoruniversalcomrotacao/control \
sim:/registradoruniversalcomrotacao/d_to_right \
sim:/registradoruniversalcomrotacao/d_to_left \
sim:/registradoruniversalcomrotacao/palavra \
sim:/registradoruniversalcomrotacao/q \
sim:/registradoruniversalcomrotacao/r_reg \
sim:/registradoruniversalcomrotacao/r_next

force -freeze sim:/registradoruniversalcomrotacao/reset 1 0
force -freeze sim:/registradoruniversalcomrotacao/clk 0 0
run
force -freeze sim:/registradoruniversalcomrotacao/clk 1 0
run
force -freeze sim:/registradoruniversalcomrotacao/clk 0 0
force -freeze sim:/registradoruniversalcomrotacao/reset 0 0
run
force -freeze sim:/registradoruniversalcomrotacao/control 111 0
force -freeze sim:/registradoruniversalcomrotacao/palavra 1011 0
force -freeze sim:/registradoruniversalcomrotacao/clk 1 0
run
force -freeze sim:/registradoruniversalcomrotacao/clk 0 0
run
force -freeze sim:/registradoruniversalcomrotacao/control 110 0
force -freeze sim:/registradoruniversalcomrotacao/clk 1 0
run
force -freeze sim:/registradoruniversalcomrotacao/clk 0 0
run
force -freeze sim:/registradoruniversalcomrotacao/control 011 0
force -freeze sim:/registradoruniversalcomrotacao/clk 1 0
run
force -freeze sim:/registradoruniversalcomrotacao/clk 0 0
run
force -freeze sim:/registradoruniversalcomrotacao/control 000 0
force -freeze sim:/registradoruniversalcomrotacao/clk 1 0
run
force -freeze sim:/registradoruniversalcomrotacao/clk 0 0
run


wave zoom full
