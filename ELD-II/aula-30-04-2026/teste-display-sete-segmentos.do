
vlib rtl_work
vmap work rtl_work
vmap work rtl_work 
vcom -93 -work work {/home/aluno/Documentos/aula-30-04-2026/bcd2dsp.vhd}

vsim work.bcd2dsp(implementacao)

add wave -position insertpoint  \
sim:/bcd2dsp/sw \
sim:/bcd2dsp/dsp
force -freeze sim:/bcd2dsp/sw 0001 0
run
force -freeze sim:/bcd2dsp/sw 0000 0
run
force -freeze sim:/bcd2dsp/sw 0010 0
run 
force -freeze sim:/bcd2dsp/sw 0011 0
run 
force -freeze sim:/bcd2dsp/sw 0100 0
run 
force -freeze sim:/bcd2dsp/sw 0101 0
run 
force -freeze sim:/bcd2dsp/sw 0110 0
run 
force -freeze sim:/bcd2dsp/sw 0111 0
run
force -freeze sim:/bcd2dsp/sw 1000 0
run 
force -freeze sim:/bcd2dsp/sw 1001 0
run 
force -freeze sim:/bcd2dsp/sw 1111 0
run 
