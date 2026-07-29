
vlib rtl_work
vmap work rtl_work

vsim work.multiplexadores(v_WITH_SELECT)

add wave -position insertpoint  \
sim:/multiplexadores/X \
sim:/multiplexadores/Sel \
sim:/multiplexadores/Y

force -freeze sim:/multiplexadores/Sel 00 0
force -freeze sim:/multiplexadores/X 0001 0
run
force -freeze sim:/multiplexadores/X 0010 0
force -freeze sim:/multiplexadores/Sel 01 0
run
force -freeze sim:/multiplexadores/X 0100 0
force -freeze sim:/multiplexadores/Sel 10 0
run
force -freeze sim:/multiplexadores/X 1000 0
force -freeze sim:/multiplexadores/Sel 11 0
run


