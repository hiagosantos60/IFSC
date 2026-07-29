vlib rtl_work
vmap work rtl_work
vmap work rtl_work 

vcom -93 -work work {/home/hiago.s2006/eld-II/aula-07-05-2026/FlipFlopComEnable.vhd}

vsim rtl_work.flipflopcomenable(implementacao_v1)

add wave -position insertpoint  \
sim:/flipflopcomenable/clk \
sim:/flipflopcomenable/d \
sim:/flipflopcomenable/q \
sim:/flipflopcomenable/rst \
sim:/flipflopcomenable/enable \
sim:/flipflopcomenable/estadoAtual

force -freeze sim:/flipflopcomenable/enable 1 0
force -freeze sim:/flipflopcomenable/rst 1 0
force -freeze sim:/flipflopcomenable/clk 0 0
force -freeze sim:/flipflopcomenable/d 0 0
run
force -freeze sim:/flipflopcomenable/rst 0 0
force -freeze sim:/flipflopcomenable/clk 1 0
force -freeze sim:/flipflopcomenable/d 1 0
run
force -freeze sim:/flipflopcomenable/clk 0 0
force -freeze sim:/flipflopcomenable/d 0 0
run
force -freeze sim:/flipflopcomenable/clk 1 0
run
force -freeze sim:/flipflopcomenable/enable 0 0
force -freeze sim:/flipflopcomenable/clk 0 0
force -freeze sim:/flipflopcomenable/d 1 0
run
force -freeze sim:/flipflopcomenable/clk 1 0
run
force -freeze sim:/flipflopcomenable/rst 1 0
run
