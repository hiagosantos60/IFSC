--=============================================================================
-- Componente que sincroniza os sinais dos push-buttons com deteccao da borda 
-- de subida
-- Author: Roberto de Matos
--=============================================================================

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity sync_keys is
  port(
      clk, reset: in std_logic;
      keys_i: in std_logic_vector(2 downto 0);  -- entradas assíncronas
      keys_o: out std_logic_vector(2 downto 0)  -- saídas sincronizadas 
   );
end sync_keys;

architecture arch of sync_keys is
  signal sync0: std_ulogic_vector(2 downto 0);
  signal sync1: std_ulogic_vector(2 downto 0);
  signal sync2: std_ulogic_vector(2 downto 0);
begin
  -- register
  process(clk,reset)
  begin
    if (reset='1') then
      sync0 <= (others=>'0');
      sync1 <= (others=>'0');
      sync2 <= (others=>'0');
    elsif (clk'event and clk='1') then
      sync0 <= keys_i(0) & sync0(2 downto 1);
      sync1 <= keys_i(1) & sync1(2 downto 1);
      sync2 <= keys_i(2) & sync2(2 downto 1);
    end if;
  end process;

  keys_o(0) <= sync0(1) and (not sync0(0));
  keys_o(1) <= sync1(1) and (not sync1(0));
  keys_o(2) <= sync2(1) and (not sync2(0));
  
end arch;
