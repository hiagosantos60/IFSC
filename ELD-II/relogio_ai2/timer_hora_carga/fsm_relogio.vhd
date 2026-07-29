library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity fsm_relogio is
    port
    (
        clk      : in std_logic;
        reset    : in std_logic; -- KEY[0]
        adjust   : in std_logic; -- KEY[1]
        plus     : in std_logic; -- KEY[2]
        less     : in std_logic; -- KEY[3]
        hour_in  : in std_logic_vector(4 downto 0);
        min_in   : in std_logic_vector(5 downto 0);
        seg_in   : in std_logic_vector(5 downto 0);

        blink_h  : out std_logic;
        blink_m  : out std_logic;
        blink_s  : out std_logic;
        load     : out std_logic;
        hour_out : out std_logic_vector(4 downto 0);
        min_out  : out std_logic_vector(5 downto 0);
        seg_out  : out std_logic_vector(5 downto 0)
    );
end fsm_relogio;

architecture fsm_relogio_implementacao of fsm_relogio is
    type mc_state_type is (
        IDLE,
        AJUSTE_HORA, PLUS_HOUR, LESS_HOUR,
        AJUSTE_MINUTO, PLUS_MIN, LESS_MIN,
        AJUSTE_SEGUNDO, PLUS_SEG, LESS_SEG
    );

    signal state, next_state : mc_state_type;
begin
    process(clk, reset)
    begin
        if reset = '1' then
            state <= IDLE;
        elsif rising_edge(clk) then
            state <= next_state;
        end if;
    end process;

    process(state, adjust, plus, less, hour_in, min_in, seg_in)
    begin
        next_state <= state;
        hour_out   <= hour_in;
        min_out    <= min_in;
        seg_out    <= seg_in;
        blink_h    <= '0';
        blink_m    <= '0';
        blink_s    <= '0';
        load       <= '0';

        case state is
            when IDLE =>
                if adjust = '1' then next_state <= AJUSTE_HORA; end if;

            when AJUSTE_HORA =>
                blink_h <= '1';
                if plus = '1' then next_state <= PLUS_HOUR;
                elsif less = '1' then next_state <= LESS_HOUR;
                elsif adjust = '1' then next_state <= AJUSTE_MINUTO;
                end if;

            when PLUS_HOUR =>
                blink_h  <= '1';
                load     <= '1'; 
                next_state <= AJUSTE_HORA;
                -- limite: Se for 23, vai para 0
                if unsigned(hour_in) = 23 then
                    hour_out <= std_logic_vector(to_unsigned(0, 5));
                else
                    hour_out <= std_logic_vector(unsigned(hour_in) + 1);
                end if;

            when LESS_HOUR =>
                blink_h  <= '1';
                load     <= '1'; 
                next_state <= AJUSTE_HORA;
                -- limite: Se for 0, vai para 23
                if unsigned(hour_in) = 0 then
                    hour_out <= std_logic_vector(to_unsigned(23, 5));
                else
                    hour_out <= std_logic_vector(unsigned(hour_in) - 1);
                end if;

            when AJUSTE_MINUTO =>
                blink_m <= '1';
                if plus = '1' then next_state <= PLUS_MIN;
                elsif less = '1' then next_state <= LESS_MIN;
                elsif adjust = '1' then next_state <= AJUSTE_SEGUNDO;
                end if;

            when PLUS_MIN =>
                blink_m <= '1';
                load    <= '1';
                next_state <= AJUSTE_MINUTO;
                -- limite: Se for 59, vai para 0
                if unsigned(min_in) = 59 then
                    min_out <= std_logic_vector(to_unsigned(0, 6));
                else
                    min_out <= std_logic_vector(unsigned(min_in) + 1);
                end if;

            when LESS_MIN =>
                blink_m <= '1';
                load    <= '1';
                next_state <= AJUSTE_MINUTO;
                -- limite: Se for 0, vai para 59 (Resolve o bug do 63!)
                if unsigned(min_in) = 0 then
                    min_out <= std_logic_vector(to_unsigned(59, 6));
                else
                    min_out <= std_logic_vector(unsigned(min_in) - 1);
                end if;

            when AJUSTE_SEGUNDO =>
                blink_s <= '1';
                if plus = '1' then next_state <= PLUS_SEG;
                elsif less = '1' then next_state <= LESS_SEG;
                elsif adjust = '1' then next_state <= IDLE;
                end if;

            when PLUS_SEG =>
                blink_s <= '1';
                load    <= '1';
                next_state <= AJUSTE_SEGUNDO;
                -- limite: Se for 59, vai para 0
                if unsigned(seg_in) = 59 then
                    seg_out <= std_logic_vector(to_unsigned(0, 6));
                else
                    seg_out <= std_logic_vector(unsigned(seg_in) + 1);
                end if;

            when LESS_SEG =>
                blink_s <= '1';
                load    <= '1';
                next_state <= AJUSTE_SEGUNDO;
                -- limite: Se for 0, vai para 59
                if unsigned(seg_in) = 0 then
                    seg_out <= std_logic_vector(to_unsigned(59, 6));
                else
                    seg_out <= std_logic_vector(unsigned(seg_in) - 1);
                end if;

            when others =>
                next_state <= IDLE;
        end case;
    end process;

end fsm_relogio_implementacao;