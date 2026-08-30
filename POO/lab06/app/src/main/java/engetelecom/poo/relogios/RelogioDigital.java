package engetelecom.poo.relogios;

import java.time.LocalTime;

public abstract class RelogioDigital extends Relogio {

    public static final int MODO_RELOGIO = 1;
    public static final int MODO_PROGRESSIVO = 2;
    public static final int MODO_REGRESSIVO = 3;

    protected int modo;
    protected int h_cont;
    protected int m_cont;
    protected int s_cont;

    public RelogioDigital() {
        this.modo = MODO_RELOGIO;
        this.setModoRelogio();
    }

    public boolean setModoRelogio(int h, int m, int s, int modo) {
        this.modo = modo;
        if (modo == MODO_RELOGIO) {
            return setModoRelogio();
        } else if (modo == MODO_PROGRESSIVO) {
            return setModoProgressivo(h, m, s);
        } else if (modo == MODO_REGRESSIVO) {
            return setModoRegressivo(h, m, s);
        }
        return false;
    }

    public boolean setModoRelogio() {
        LocalTime l = LocalTime.now();
        int h = l.getHour();
        int m = l.getMinute();
        int s = l.getSecond();
        return setHorarioManual(h, m, s);
    }

    private boolean setModoProgressivo(int h, int m, int s) {
        if (h > 23 || h < 0 || m > 59 || m < 0 || s > 59 || s < 0)
            return false;

        this.modo = MODO_PROGRESSIVO;
        this.h_cont = h;
        this.m_cont = m;
        this.s_cont = s;

        return setHorarioManual(0, 0, 0);
    }

    private boolean setModoRegressivo(int h, int m, int s) {
        if (h > 23 || h < 0 || m > 59 || m < 0 || s > 59 || s < 0)
            return false;

        this.modo = MODO_REGRESSIVO;
        return setHorarioManual(h, m, s);
    }

    @Override
    public void avancarTempo() {
        if (this.modo == MODO_REGRESSIVO) {
            if (this.horas > 0 || this.minutos > 0 || this.segundos > 0) {
                this.segundos--;
                if (this.segundos < 0) {
                    this.segundos = 59;
                    this.minutos--;
                    if (this.minutos < 0) {
                        this.minutos = 59;
                        this.horas--;
                    }
                }
            }
        } else if (this.modo == MODO_PROGRESSIVO) {
            if (this.horas == this.h_cont && this.minutos == this.m_cont && this.segundos == this.s_cont)
                return;
            super.avancarTempo();
        } else if (this.modo == MODO_RELOGIO) {
            this.setHorario();
        }
    }

}