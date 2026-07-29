--=============================
-- Listing 10.1 memory controller FSM
--=============================
library ieee;
use ieee.std_logic_1164.all;
entity mem_ctrl is
  port (
    clk, reset     : in std_logic;
    mem, rw, burst : in std_logic;
    oe, we, we_me  : out std_logic
  );
end mem_ctrl;

architecture mult_seg_arch of mem_ctrl is
  type mc_state_type is
  (idle, read1, read2, read3, read4, write);
  signal state_reg, state_next : mc_state_type;
begin
  -- state register
  process (clk, reset)
  begin
    if (reset = '1') then
      state_reg <= idle;
    elsif (clk'event and clk = '1') then
      state_reg <= state_next;
    end if;
  end process;
  -- next-state logic
  process (state_reg, mem, rw, burst)
  begin
    case state_reg is
      when idle =>
        if mem = '1' then
          if rw = '1' then
            state_next <= read1;
          else
            state_next <= write;
          end if;
        else
          state_next <= idle;
        end if;
      when write =>
        state_next <= idle;
      when read1 =>
        if (burst = '1') then
          state_next <= read2;
        else
          state_next <= idle;
        end if;
      when read2 =>
        state_next <= read3;
      when read3 =>
        state_next <= read4;
      when read4 =>
        state_next <= idle;
    end case;
  end process;
  -- Moore output logic
  process (state_reg)
  begin
    we <= '0'; -- default value
    oe <= '0'; -- default value
    case state_reg is
      when idle  =>
      when write =>
        we <= '1';
      when read1 =>
        oe <= '1';
      when read2 =>
        oe <= '1';
      when read3 =>
        oe <= '1';
      when read4 =>
        oe <= '1';
    end case;
  end process;
  -- Mealy output logic
  process (state_reg, mem, rw)
  begin
    we_me <= '0'; -- default value
    case state_reg is
      when idle =>
        if (mem = '1') and (rw = '0') then
          we_me <= '1';
        end if;
      when write =>
      when read1 =>
      when read2 =>
      when read3 =>
      when read4 =>
    end case;
  end process;
end mult_seg_arch;
--=============================
-- Listing 10.2
--=============================
architecture two_seg_arch of mem_ctrl is
  type mc_state_type is
  (idle, read1, read2, read3, read4, write);
  signal state_reg, state_next : mc_state_type;
begin
  -- state register
  process (clk, reset)
  begin
    if (reset = '1') then
      state_reg <= idle;
    elsif (clk'event and clk = '1') then
      state_reg <= state_next;
    end if;
  end process;
  -- next-state logic and output logic
  process (state_reg, mem, rw, burst)
  begin
    oe    <= '0'; -- default values
    we    <= '0';
    we_me <= '0';
    case state_reg is
      when idle =>
        if mem = '1' then
          if rw = '1' then
            state_next <= read1;
          else
            state_next <= write;
            we_me      <= '1';
          end if;
        else
          state_next <= idle;
        end if;
      when write =>
        state_next <= idle;
        we         <= '1';
      when read1 =>
        if (burst = '1') then
          state_next <= read2;
        else
          state_next <= idle;
        end if;
        oe <= '1';
      when read2 =>
        state_next <= read3;
        oe         <= '1';
      when read3 =>
        state_next <= read4;
        oe         <= '1';
      when read4 =>
        state_next <= idle;
        oe         <= '1';
    end case;
  end process;
end two_seg_arch;
--=============================
-- Listing 10.3
--=============================
architecture one_seg_wrong_arch of mem_ctrl is
  type mc_state_type is
  (idle, read1, read2, read3, read4, write);
  signal state_reg : mc_state_type;
begin
  process (clk, reset)
  begin
    if (reset = '1') then
      state_reg <= idle;
    elsif (clk'event and clk = '1') then
      oe    <= '0'; -- default values
      we    <= '0';
      we_me <= '0';
      case state_reg is
        when idle =>
          if mem = '1' then
            if rw = '1' then
              state_reg <= read1;
            else
              state_reg <= write;
              we_me     <= '1';
            end if;
          else
            state_reg <= idle;
          end if;
        when write =>
          state_reg <= idle;
          we        <= '1';
        when read1 =>
          if (burst = '1') then
            state_reg <= read2;
          else
            state_reg <= idle;
          end if;
          oe <= '1';
        when read2 =>
          state_reg <= read3;
          oe        <= '1';
        when read3 =>
          state_reg <= read4;
          oe        <= '1';
        when read4 =>
          state_reg <= idle;
          oe        <= '1';
      end case;
    end if;
  end process;
end one_seg_wrong_arch;
--=============================
-- Listing 10.4
--=============================
architecture state_assign_arch of mem_ctrl is
  constant idle                : std_logic_vector(3 downto 0) := "0000";
  constant write               : std_logic_vector(3 downto 0) := "0100";
  constant read1               : std_logic_vector(3 downto 0) := "1000";
  constant read2               : std_logic_vector(3 downto 0) := "1001";
  constant read3               : std_logic_vector(3 downto 0) := "1010";
  constant read4               : std_logic_vector(3 downto 0) := "1011";
  signal state_reg, state_next : std_logic_vector(3 downto 0);
begin
  -- state register
  process (clk, reset)
  begin
    if (reset = '1') then
      state_reg <= idle;
    elsif (clk'event and clk = '1') then
      state_reg <= state_next;
    end if;
  end process;
  -- next-state logic
  process (state_reg, mem, rw, burst)
  begin
    case state_reg is
      when idle =>
        if mem = '1' then
          if rw = '1' then
            state_next <= read1;
          else
            state_next <= write;
          end if;
        else
          state_next <= idle;
        end if;
      when write =>
        state_next <= idle;
      when read1 =>
        if (burst = '1') then
          state_next <= read2;
        else
          state_next <= idle;
        end if;
      when read2 =>
        state_next <= read3;
      when read3 =>
        state_next <= read4;
      when read4 =>
        state_next <= idle;
      when others =>
        state_next <= idle;
    end case;
  end process;
  -- Moore output logic
  process (state_reg)
  begin
    we <= '0'; -- default value
    oe <= '0'; -- default value
    case state_reg is
      when idle  =>
      when write =>
        we <= '1';
      when read1 =>
        oe <= '1';
      when read2 =>
        oe <= '1';
      when read3 =>
        oe <= '1';
      when read4 =>
        oe <= '1';
      when others =>
    end case;
  end process;
  -- Mealy output logic
  we_me <= '1' when ((state_reg = idle) and (mem = '1') and
    (rw = '0')) else
    '0';
end state_assign_arch;
--=============================
-- Listing 10.5
--=============================
architecture plain_buffer_arch of mem_ctrl is
  type mc_state_type is
  (idle, read1, read2, read3, read4, write);
  signal state_reg, state_next              : mc_state_type;
  signal oe_i, we_i, oe_buf_reg, we_buf_reg : std_logic;
begin
  -- state register
  process (clk, reset)
  begin
    if (reset = '1') then
      state_reg <= idle;
    elsif (clk'event and clk = '1') then
      state_reg <= state_next;
    end if;
  end process;
  -- output buffer
  process (clk, reset)
  begin
    if (reset = '1') then
      oe_buf_reg <= '0';
      we_buf_reg <= '0';
    elsif (clk'event and clk = '1') then
      oe_buf_reg <= oe_i;
      we_buf_reg <= we_i;
    end if;
  end process;
  -- next-state logic
  process (state_reg, mem, rw, burst)
  begin
    case state_reg is
      when idle =>
        if mem = '1' then
          if rw = '1' then
            state_next <= read1;
          else
            state_next <= write;
          end if;
        else
          state_next <= idle;
        end if;
      when write =>
        state_next <= idle;
      when read1 =>
        if (burst = '1') then
          state_next <= read2;
        else
          state_next <= idle;
        end if;
      when read2 =>
        state_next <= read3;
      when read3 =>
        state_next <= read4;
      when read4 =>
        state_next <= idle;
    end case;
  end process;
  -- Moore output logic
  process (state_reg)
  begin
    we_i <= '0'; -- default value
    oe_i <= '0'; -- default value
    case state_reg is
      when idle  =>
      when write =>
        we_i <= '1';
      when read1 =>
        oe_i <= '1';
      when read2 =>
        oe_i <= '1';
      when read3 =>
        oe_i <= '1';
      when read4 =>
        oe_i <= '1';
    end case;
  end process;
  -- output
  we <= we_buf_reg;
  oe <= oe_buf_reg;
end plain_buffer_arch;
--=============================
-- Listing 10.6
--=============================
architecture look_ahead_buffer_arch of mem_ctrl is
  type mc_state_type is
  (idle, read1, read2, read3, read4, write);
  signal state_reg, state_next                    : mc_state_type;
  signal oe_next, we_next, oe_buf_reg, we_buf_reg : std_logic;
begin
  -- state register
  process (clk, reset)
  begin
    if (reset = '1') then
      state_reg <= idle;
    elsif (clk'event and clk = '1') then
      state_reg <= state_next;
    end if;
  end process;
  -- output buffer
  process (clk, reset)
  begin
    if (reset = '1') then
      oe_buf_reg <= '0';
      we_buf_reg <= '0';
    elsif (clk'event and clk = '1') then
      oe_buf_reg <= oe_next;
      we_buf_reg <= we_next;
    end if;
  end process;
  -- next-state logic
  process (state_reg, mem, rw, burst)
  begin
    case state_reg is
      when idle =>
        if mem = '1' then
          if rw = '1' then
            state_next <= read1;
          else
            state_next <= write;
          end if;
        else
          state_next <= idle;
        end if;
      when write =>
        state_next <= idle;
      when read1 =>
        if (burst = '1') then
          state_next <= read2;
        else
          state_next <= idle;
        end if;
      when read2 =>
        state_next <= read3;
      when read3 =>
        state_next <= read4;
      when read4 =>
        state_next <= idle;
    end case;
  end process;
  -- look-ahead output logic
  process (state_next)
  begin
    we_next <= '0'; -- default value
    oe_next <= '0'; -- default value
    case state_next is
      when idle  =>
      when write =>
        we_next <= '1';
      when read1 =>
        oe_next <= '1';
      when read2 =>
        oe_next <= '1';
      when read3 =>
        oe_next <= '1';
      when read4 =>
        oe_next <= '1';
    end case;
  end process;
  -- output
  we <= we_buf_reg;
  oe <= oe_buf_reg;
end look_ahead_buffer_arch;
