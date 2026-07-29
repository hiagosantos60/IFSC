
vlib rtl_work
vmap work rtl_work

vcom -93 -work work {/home/hiago.s2006/eld-II/aula-28-04-2026/atribuicao_sequencial.vhd}

vsim work.atribuicao_sequencial(atribuicao_correta_v1)

add wave -position insertpoint  \
sim:/atribuicao_sequencial/a \
sim:/atribuicao_sequencial/b \
sim:/atribuicao_sequencial/gt \
sim:/atribuicao_sequencial/eq \
sim:/atribuicao_sequencial/lt
force -freeze sim:/atribuicao_sequencial/a 10000000 0
force -freeze sim:/atribuicao_sequencial/b 10000000 0
run
force -freeze sim:/atribuicao_sequencial/b 00000001 0
run
force -freeze sim:/atribuicao_sequencial/a 11111111 0
force -freeze sim:/atribuicao_sequencial/b 10000000 0
run
force -freeze sim:/atribuicao_sequencial/a 11111011 0
force -freeze sim:/atribuicao_sequencial/b 11111011 0
run
force -freeze sim:/atribuicao_sequencial/a 11111111 0
force -freeze sim:/atribuicao_sequencial/b 00000000 0
run
force -freeze sim:/atribuicao_sequencial/a 00000000 0
force -freeze sim:/atribuicao_sequencial/b 11111111 0
run

