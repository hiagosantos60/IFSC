library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity top_timer_de2_115 is
  port (
    CLOCK_50 : in std_logic;
    KEY      : in std_logic_vector (0 downto 0);
    HEX0     : out std_logic_vector (6 downto 0);
    HEX1     : out std_logic_vector (6 downto 0);
    HEX2     : out std_logic_vector (6 downto 0);
    HEX3     : out std_logic_vector (6 downto 0);
	 HEX4     : out std_logic_vector (6 downto 0);
	 HEX5     : out std_logic_vector (6 downto 0)
  );

end entity;

architecture top_a3_2019_2 of top_timer_de2_115 is

component pll4_50mhz IS
	PORT
	(
		inclk0		: IN STD_LOGIC  := '0';
		c0		: OUT STD_LOGIC 
	);
END component;

  component timer
    port (
      clk, reset : in std_logic;
      sec, min    : out std_logic_vector(5 downto 0);
		hrs : out std_logic_vector(5 downto 0)
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

  component bcd2ssd
    port (
      BCD : in std_logic_vector (3 downto 0);
      SSD : out std_logic_vector (6 downto 0)
    );
  end component;

  signal minT, minU : std_logic_vector(3 downto 0);
  signal secT, secU : std_logic_vector(3 downto 0);
  signal hrsT, hrsU : std_logic_vector(3 downto 0);
  signal min, sec, hrs         : std_logic_vector(5 downto 0);
  signal r_reg, r_next    : unsigned(22 downto 0);
  signal reset            : std_logic;
  signal clk_2khz            : std_logic;

begin

  reset <= not KEY(0);
  
  pll4_50mhz_inst : pll4_50mhz PORT MAP (
		inclk0	 => CLOCK_50,
		c0	 => clk_2khz
	);

  t0 : entity work.timer(single_clock_arch)
  port map(
    clk   => clk_2khz,
    reset => reset,
    sec   => sec,
    min   => min,
	 hrs	 => hrs	);


  bin2bcd0: bin2bcd
  generic map (
    N => 6)
  port map (
    clk => clk_2khz, 
    reset => reset,
    binary_in => sec,
    bcd0 => secU,
    bcd1 => secT, 
    bcd2 => open,
    bcd3 => open,
    bcd4 => open);

  bin2bcd1: bin2bcd
  generic map (
    N => 6)
  port map (
    clk => clk_2khz, 
    reset => reset,
    binary_in => min,
    bcd0 => minU,
    bcd1 => minT, 
    bcd2 => open,
    bcd3 => open,
    bcd4 => open);
	 
	bin2bcd2: bin2bcd
  generic map (
    N => 6)
  port map (
    clk => clk_2khz, 
    reset => reset,
    binary_in => hrs,
    bcd0 => hrsU,
    bcd1 => hrsT, 
    bcd2 => open,
    bcd3 => open,
    bcd4 => open); 


  bcd0 : bcd2ssd
  port map(
    BCD => secU,
    SSD => HEX0);

  bcd1 : bcd2ssd
  port map(
    BCD => secT,
    SSD => HEX1);

  bcd2 : bcd2ssd
  port map(
    BCD => minU,
    SSD => HEX2);

  bcd3 : bcd2ssd
  port map(
    BCD => minT,
    SSD => HEX3);
	 
	bcd4 : bcd2ssd
  port map(
    BCD => hrsU,
    SSD => HEX4);
	 
	bcd5 : bcd2ssd
  port map(
    BCD => hrsT,
    SSD => HEX5);	 

end top_a3_2019_2;
