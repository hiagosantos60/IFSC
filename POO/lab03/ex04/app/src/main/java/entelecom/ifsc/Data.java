package entelecom.ifsc;

public class Data {
    private int dia;
    private int mes;
    private int ano;

    //mes começa em 1
    int[] meses = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    @Override
    public String toString() {
        return String.format("%d/%s/%d", dia, mes, ano);
    }

    // validação ano bissesto
    private boolean isBissexto(int ano) {
        if (ano%4 == 0){
            if (ano%100 == 0 && ano%400 != 0) {
                return false;
            } else{
                return true;
            }
        } else {
            return false;
        }
    }

    public Data(int dia, int mes, int ano) {
        if (mes < 1 || mes > 13 || dia < 1 || dia > meses[mes] || ano < 0) {
            this.ano = 1970;
            this.dia = 1;
            this.mes = 1;
        } else {
            setAno(ano);
            setMes(mes);
            setDia(dia);
        }
    }

    public boolean setDia(int dia) {
        if (this.mes < 1 || this.mes > 12) {
        return false; 
        }

        if (dia < 1 || dia > meses[this.mes]) {
            return false;
        } else {
            this.dia = dia;
            return true;
        }
    }

    public boolean setMes(int mes) {
        if (mes > 0 && mes < 13) {
            this.mes = mes;
            return true;
        } else return false;
    }

    public boolean setAno(int ano) {
        if (isBissexto(ano) == true)  {
            meses[3] = 29;
        } else {
            meses[3] = 28;
        }
        
        this.ano = ano;
        return true;
    }

    public String porExtenso() {
        //Poderia ter usado string builder ao invés de switch case

        String m = "";

        switch (this.mes) {
            case 1:
                m = "Janeiro";
                break;
            case 2:
                m = "Fevereiro";
                break;
            case 3:
                m = "Março";
                break;
            case 4:
                m = "Abril";
                break;
            case 5:
                m = "Maio";
                break;
            case 6:
                m = "Junho";
                break;
            case 7:
                m = "Julho";
                break;
            case 8:
                m = "Agosto";
                break;
            case 9:
                m = "Setembro";
                break;
            case 10:
                m = "Outubro";
                break;
            case 11:
                m = "Novembro";
                break;
            case 12:
                m = "Dezembro";
                break;
            default:
                break;
        }

        return dia + " de " + m + " de " + ano; 
    }


    private int totalDias(){
        int total=0;

        //soma todos os dias dos meses entre eles
        for (int i = 1; i < this.mes; i++) {
            total += meses[i];
        }

        //soma os dias do mes atual
        total += this.dia;
        
        return total;
    }

    public int calcularDiferenca(Data d) {
        int diasUm = this.totalDias();
        int diasDois = d.totalDias();

        // diferença entre os totais de dias até a data para comparar
        int diferenca = Math.abs(diasUm - diasDois);

        return diferenca;
    }
}
