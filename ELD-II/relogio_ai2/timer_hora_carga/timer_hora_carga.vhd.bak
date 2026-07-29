--======================================
-- Timer com hora e sinal de carga
-- Adaptado do Listing 9.5 timer
-- Adaptacao: Roberto de Matos
--======================================
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity timer is
   port(
      clk, reset: in std_logic;
		load : in std_logic;
		hour_i: in std_logic_vector(4 downto 0);
      sec_i,min_i: in std_logic_vector(5 downto 0);
      hour: out std_logic_vector(4 downto 0);
      sec,min: out std_logic_vector(5 downto 0)
   );
end timer;

architecture single_clock_arch of timer is
  signal r_reg: unsigned(25 downto 0);
  signal r_next: unsigned(25 downto 0);
  signal h_reg: unsigned(4 downto 0);
  signal h_next: unsigned(4 downto 0);
  signal s_reg, m_reg: unsigned(5 downto 0);
  signal s_next, m_next: unsigned(5 downto 0);
  signal s_en, m_en, h_en: std_logic;
begin
  -- register
  process(clk,reset)
  begin
     if (reset='1') then
        r_reg <= (others=>'0');
        s_reg <= (others=>'0');
        m_reg <= (others=>'0');
        h_reg <= (others=>'0');        
     elsif (clk'event and clk='1') then
        r_reg <= r_next;
        s_reg <= s_next;
        m_reg <= m_next;
        h_reg <= h_next;
     end if;
  end process;
  -- next-state logic/output logic for mod-50000000 counter
  r_next <= (others=>'0') when (r_reg=49999999 or load='1') else
            r_reg + 1;
  s_en <= '1' when r_reg = 49999999 else
          '0';
  -- next state logic/output logic for second divider
  s_next <= unsigned(sec_i) when (load='1') else
				(others=>'0') when (s_reg=59 and s_en='1') else
            s_reg + 1     when s_en='1' else
            s_reg;
  m_en <= '1' when s_reg=59 and s_en='1' else
          '0';
  -- next-state logic for minute divider
  m_next <= unsigned(min_i) when (load='1') else
				(others=>'0') when (m_reg=59 and m_en='1') else
            m_reg + 1     when m_en='1' else
            m_reg;

  h_en <= '1' when m_reg=59 and m_en='1' else
          '0';

  -- next-state logic for hour divider
  h_next <= unsigned(hour_i) when (load='1') else
				(others=>'0') when (h_reg=23 and h_en='1') else
            h_reg + 1     when h_en='1' else
            h_reg;

  -- output logic
  sec <= std_logic_vector(s_reg);
  min <= std_logic_vector(m_reg);
  hour <= std_logic_vector(h_reg);
end single_clock_arch;
