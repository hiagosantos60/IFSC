package engetelecom.poo.relogios;

import java.time.LocalTime;
import edu.princeton.cs.algs4.Draw;

public abstract class Relogio {
    protected int horas;
    protected int minutos;
    protected int segundos;
    protected int posX;
    protected int posY;

    public boolean setHorarioManual(int h, int m, int s) {
        // Validação correta: hora vai até 23
        if (h > 23 || h < 0 || m > 59 || m < 0 || s > 59 || s < 0) return false;
        this.horas = h;
        this.minutos = m;
        this.segundos = s;
        return true;
    }

    public boolean setHorario() {
        LocalTime l = LocalTime.now();
        this.horas = l.getHour();
        this.minutos = l.getMinute();
        this.segundos = l.getSecond();
        return true;
    }

    public void avancarTempo() {
        this.segundos++;
        if (this.segundos == 60) {
            this.segundos = 0;
            this.minutos++;
            
            if (this.minutos == 60) {
                this.minutos = 0;
                this.horas++;
                
                if (this.horas == 24) {
                    this.horas = 0;
                }
            }
        }
    }

    public abstract void desenhar(Draw canvas);
}