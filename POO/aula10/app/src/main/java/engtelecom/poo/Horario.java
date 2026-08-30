package engtelecom.poo;

public class Horario {
    private int hora;
    private int minuto;
    private int segundo;

    private static final int MAX_HORA = 23;
    private static final int MIN_HORA = 0;
    private static final int MAX_MIN = 59;
    private static final int MIN_MIN = 0;
    private static final int MAX_SEG = 59;
    private static final int MIN_SEG = 0;


    @Override
    public String toString() {
        return String.format("%02d:%02d:%02d", hora, minuto, segundo);
    }

    public void setHorario(int hora, int minuto, int segundo) {
        if (hora < MIN_HORA || hora > MAX_HORA || minuto > MAX_MIN || minuto < MIN_MIN || segundo > MAX_SEG || segundo < MIN_SEG) {
            return;
        } else {
            this.hora = hora;
            this.minuto = minuto;
            this.segundo = segundo;
        }
    }

    public void setHorario(int hora, int minuto) {
        setHorario(hora, minuto, 0);
    }
    
    public void setHorario(int hora) {
        setHorario(hora, 0 ,0);
    }
}
