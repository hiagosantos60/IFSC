package engtelecom.poo;

public class Horario {
    private int horas;
    private int minutos;
    private int segundos;

    private static final int MAX_HORA = 23;
    private static final int MIN_HORA = 0;
    private static final int MAX_MIN = 59;
    private static final int MIN_MIN = 0;
    private static final int MAX_SEG = 59;
    private static final int MIN_SEG = 0;

    public Horario(int horas, int minutos, int segundos) {
        // caso algum valor seja inválido, coloque tudo zero
        if (horas > MAX_HORA || horas < MIN_MIN ||
            minutos > MAX_MIN || minutos < MIN_MIN ||
            segundos > MAX_SEG || segundos < MIN_SEG
        ) {
            this.horas = 0;
            this.minutos = 0;
            this.segundos = 0;
        } else {
            this.horas = horas;
            this.minutos = minutos;
            this.segundos = segundos;
        }
    }

    public Horario(int horas, int minutos) {
        this(horas , minutos,0);
    }

    public Horario(int horas) {
        this(horas, 0 ,0);
    }

    public Boolean setHoras(int horas) {
        if (horas > MAX_HORA || horas < MIN_HORA) {
            return false;
        } else {
            this.horas = horas;
            return true;
        }
    }

    public Boolean setMinutos(int minutos) {
        if (minutos > MAX_MIN || minutos < MIN_MIN) {
            return false;
        } else {
            this.minutos = minutos;
            return true;
        }
    }

    public Boolean setSegundos(int segundos) {
        if (segundos > MAX_SEG || segundos < MIN_SEG) {
            return false;
        } else {
            this.segundos = segundos;
            return true;
        }
    }

    public int getHoras() {
        return horas;
    }

    public int getMinutos() {
        return minutos;
    }

    public int getSegundos() {
        return segundos;
    }

    @Override
    public String toString() {
        return String.format("%d:%d:%d", horas, minutos, segundos);
    }

    public long converteParaSegundos() {
        return (this.horas * 3600 + this.minutos * 60 + segundos);
    }

    private String converteParaExtenso(int valor) {
        return switch (valor) {
            case 1 -> "um";
            case 2 -> "dois";
            case 3 -> "três";
            case 4 -> "quatro";
            case 5 -> "cinco";
            case 6 -> "seis";
            case 7 -> "sete";
            case 8 -> "oito";
            case 9 -> "nove";
            case 10 -> "dez";
            case 11 -> "onze";
            case 12 -> "doze";
            case 13 -> "treze";
            case 14 -> "catorze";
            case 15 -> "quinze";
            case 16 -> "dezesseis";
            case 17 -> "dezessete";
            case 18 -> "dezoito";
            case 19 -> "dezenove";
            case 20 -> "vinte";
            case 30 -> "trinta";
            case 40 -> "quarenta";
            case 50 -> "cinquenta";
            default -> "";
        };
    }

    public String paraExtenso() {
        int horaDezena = (this.horas / 10) * 10;
        int horaUnidade = (this.horas % 10);
        int minutoDezena = (this.minutos / 10) * 10;
        int minutoUnidae = (this.minutos % 10);
        int segundosDezena = (this.segundos / 10) * 10;
        int segundosUnidade = (this.segundos % 10);



        String h = (this.horas == 1) ? "uma hora" : (this.horas == 2) ? "duas" : (this.horas < 20) ?
         converteParaExtenso(this.horas) + " horas " : converteParaExtenso(horaDezena) + " e " + converteParaExtenso(horaUnidade) + " horas "; 

        String m = (this.minutos == 1 ) ? "um minuto " : (this.minutos < 20) ? converteParaExtenso(this.minutos) + " minutos " : 
         converteParaExtenso(minutoDezena) + " e " + converteParaExtenso(minutoUnidae) + " minutos ";

        String s = (this.segundos == 1 ) ? "e um segundo" : (this.segundos < 20) ? converteParaExtenso(this.segundos) + " segundos " :
         converteParaExtenso(segundosDezena) + " e " + converteParaExtenso(segundosUnidade) + " segundos ";

        return h+m+"e "+s;
    }
}