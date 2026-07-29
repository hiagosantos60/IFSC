

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity top_timer_de2_115 is
  port (
    CLOCK_50 : in std_logic;
    KEY      : in std_logic_vector (3 downto 0); -- ajustado para 4 keys
    HEX0     : out std_logic_vector (6 downto 0);
    HEX1     : out std_logic_vector (6 downto 0);
    HEX2     : out std_logic_vector (6 downto 0);
    HEX3     : out std_logic_vector (6 downto 0);
    HEX4     : out std_logic_vector (6 downto 0);	
    HEX5     : out std_logic_vector (6 downto 0)
  );
end entity;

architecture top of top_timer_de2_115 is
  -- declaracao dos componentes
  component timer is
    port (
      clk, reset   : in std_logic;
      load         : in std_logic;
      hour_i       : in std_logic_vector(4 downto 0);
      sec_i, min_i : in std_logic_vector(5 downto 0);
      hour         : out std_logic_vector(4 downto 0);      
      sec, min     : out std_logic_vector(5 downto 0)
    );
  end component;

  component bin2bcd is
    generic (N : positive := 16);
    port (
      clk, reset                   : in std_logic;
      binary_in                    : in std_logic_vector(N - 1 downto 0);
      bcd0, bcd1, bcd2, bcd3, bcd4 : out std_logic_vector(3 downto 0)
    );
  end component;
  
  component blink is
    port(
      clk, reset, en : in std_logic;
      blink          : out std_logic
    );
  end component;

  component bcd2ssd is
    port (
      BCD : in std_logic_vector (3 downto 0);
      SSD : out std_logic_vector (6 downto 0)
    );
  end component;

  -- declaracao da fsm_relogio como componente
  component fsm_relogio is
    port (
      clk, reset, adjust, plus, less : in std_logic;
      hour_in                        : in std_logic_vector(4 downto 0);
      min_in, seg_in                 : in std_logic_vector(5 downto 0);
      blink_h, blink_m, blink_s      : out std_logic;
      load                           : out std_logic;
      hour_out                       : out std_logic_vector(4 downto 0);
      min_out, seg_out               : out std_logic_vector(5 downto 0)
    );
  end component;

  -- declarando o sincronizador de botões como componente
  component sync_keys is
    port(
      clk, reset : in std_logic;
      keys_i     : in std_logic_vector(2 downto 0);                                                                                                                                                               
      keys_o     : out std_logic_vector(2 downto 0)  
    );
  end component;

  -- declarações de sinais internos
  signal reset : std_logic;

  -- sinais dos Botoes
  signal raw_keys    : std_logic_vector(2 downto 0); -- leitura dos botoes apenas
  signal syncro_keys : std_logic_vector(2 downto 0); -- leitura dos botoes sincronizados
  signal adjust_sig  : std_logic; -- sinal de ajuste para prox estado
  signal plus_sig    : std_logic; -- incrementa
  signal less_sig    : std_logic; -- decrementa

  -- horario atual que vai vir de timer
  signal hour_current : std_logic_vector(4 downto 0);
  signal min_current  : std_logic_vector(5 downto 0);
  signal sec_current  : std_logic_vector(5 downto 0);

  -- sinais de ajuste (saida da FSM -> entrada do timer)
  signal fsm_hour_out : std_logic_vector(4 downto 0);
  signal fsm_min_out  : std_logic_vector(5 downto 0);
  signal fsm_sec_out  : std_logic_vector(5 downto 0);
  signal fsm_load     : std_logic;

  -- sinais de blink
  signal blink_h, 
         blink_m, 
         blink_s          : std_logic;
  signal fsm_any_blink    : std_logic;
  signal blink_oscillator : std_logic;

  -- bcd para o display
  signal hourT, hourU : std_logic_vector(3 downto 0);
  signal minT, minU   : std_logic_vector(3 downto 0);
  signal secT, secU   : std_logic_vector(3 downto 0);
  
  signal hourT_blink, 
         hourU_blink  : std_logic_vector(3 downto 0);
  signal minT_blink, 
         minU_blink   : std_logic_vector(3 downto 0);
  signal secT_blink, 
         secU_blink   : std_logic_vector(3 downto 0);

begin

  -- reset
  reset <= not KEY(0);
  
  -- pega os botões 1, 2 e 3, inverte, e joga no sincronizador
  raw_keys(0) <= not KEY(1); -- Adjust
  raw_keys(1) <= not KEY(2); -- Plus
  raw_keys(2) <= not KEY(3); -- Less

  -- instanciando sincronizador de teclas
  inst_sync_keys: sync_keys 
  port map(
    clk    => CLOCK_50,
    reset  => reset,
    keys_i => raw_keys,
    keys_o => syncro_keys
  );

  -- depois de sincronizar, pegar cada sinal
  adjust_sig <= syncro_keys(0);
  plus_sig   <= syncro_keys(1);
  less_sig   <= syncro_keys(2);

  -- instanciando componente da fsm_relogio
  inst_fsm: fsm_relogio 
  port map(
    clk      => CLOCK_50,
    reset    => reset,
    adjust   => adjust_sig,
    plus     => plus_sig,
    less     => less_sig,
    
    -- fsm lê a hora atual do timer
    hour_in  => hour_current,
    min_in   => min_current,
    seg_in   => sec_current,
    
    -- fsm controla os displays e o carregamento do Timer
    blink_h  => blink_h,
    blink_m  => blink_m,
    blink_s  => blink_s,
    load     => fsm_load,
    
    -- fsm devolve a hora adjusted de volta pro timer
    hour_out => fsm_hour_out,
    min_out  => fsm_min_out,
    seg_out  => fsm_sec_out
  );

  -- instanciando o timer
  t0 : timer 
  port map(
    clk    => CLOCK_50,
    reset  => reset,
    
    -- sinais que vem da fsm
    load   => fsm_load,
    hour_i => fsm_hour_out,
    min_i  => fsm_min_out,
    sec_i  => fsm_sec_out,
    
    -- envia a hora atualizada para os displays e para a fsm ler
    hour   => hour_current,
    min    => min_current,
    sec    => sec_current
  );

  -- pisca se um dos três estiver mandando piscar
  fsm_any_blink <= blink_h or blink_m or blink_s;

  blink1: blink 
  port map(
    clk   => CLOCK_50,
    reset => reset,
    en    => fsm_any_blink, -- ajustado enable
    blink => blink_oscillator
  );
  
  secU_blink <= (others=>'1') when (blink_oscillator='1' and blink_s='1') else 
                secU;
  secT_blink <= (others=>'1') when (blink_oscillator='1' and blink_s='1') else 
                secT;
  
  minU_blink <= (others=>'1') when (blink_oscillator='1' and blink_m='1') else 
                minU;
  minT_blink <= (others=>'1') when (blink_oscillator='1' and blink_m='1') else 
                minT;
  
  hourU_blink <= (others=>'1') when (blink_oscillator='1' and blink_h='1') else 
                 hourU;
  hourT_blink <= (others=>'1') when (blink_oscillator='1' and blink_h='1') else 
                 hourT;

  bin2bcd_sec: bin2bcd 
  generic map (
    N => 6)
  port map (
    clk       => CLOCK_50, 
    reset     => reset, 
    binary_in => sec_current, 
    bcd0      => secU, 
    bcd1      => secT, 
    bcd2      => open, 
    bcd3      => open, 
    bcd4      => open);

  bin2bcd_min: bin2bcd 
  generic map (
    N => 6)
  port map (
    clk       => CLOCK_50, 
    reset     => reset, 
    binary_in => min_current, 
    bcd0      => minU, 
    bcd1      => minT, 
    bcd2      => open, 
    bcd3      => open, 
    bcd4      => open);

  bin2bcd_hour: bin2bcd 
  generic map (
    N => 5)
  port map (
    clk       => CLOCK_50, 
    reset     => reset, 
    binary_in => hour_current, 
    bcd0      => hourU, 
    bcd1      => hourT, 
    bcd2      => open, 
    bcd3      => open, 
    bcd4      => open);

  bcd_secU : bcd2ssd 
  port map(
    BCD => secU_blink, 
    SSD => HEX0);

  bcd_secT : bcd2ssd 
  port map(
    BCD => secT_blink, 
    SSD => HEX1);

  bcd_minU : bcd2ssd 
  port map(
    BCD => minU_blink, 
    SSD => HEX2);

  bcd_minT : bcd2ssd 
  port map(
    BCD => minT_blink, 
    SSD => HEX3);

  bcd_hourU : bcd2ssd 
  port map(
    BCD => hourU_blink, 
    SSD => HEX4);

  bcd_hourT : bcd2ssd 
  port map(
    BCD => hourT_blink, 
    SSD => HEX5);   

end top;