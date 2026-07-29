
vsim work.sync_keys

add wave -position insertpoint  -radix binary \
sim:/sync_keys/clk \
sim:/sync_keys/reset \
sim:/sync_keys/keys_i \
sim:/sync_keys/keys_o \
sim:/sync_keys/sync0 \
sim:/sync_keys/sync1 \
sim:/sync_keys/sync2 

# Criando clock e forçando reset
force -freeze sim:/sync_keys/clk 1 0, 0 {10000 ps} -r 20ns
force -freeze sim:/sync_keys/reset 1 0 
force -freeze sim:/sync_keys/keys_i 4'b000 0
run 40ns
force -freeze sim:/sync_keys/reset 0 0 
run 40ns

# Forcando alguns valores de borda para verificar o funcionamento
force -freeze sim:/sync_keys/keys_i 4'b000 0
run 200ns

force -freeze sim:/sync_keys/keys_i 4'b111 0
run 200ns

force -freeze sim:/sync_keys/keys_i 4'b000 0
run 200ns

force -freeze sim:/sync_keys/keys_i 4'b111 0
run 200ns


