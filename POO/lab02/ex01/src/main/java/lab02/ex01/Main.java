package lab02.ex01;

public class Main {
    static void main() {
        int dia = Integer.parseInt(IO.readln("Entre com o dia: "));
        String mes = IO.readln("Entre com o mes: ");

        String estacao;

        switch (mes.toLowerCase()) {
            case "marco" -> estacao = (dia<=20) ? "Verao" : "Outono";
            case "julho" -> estacao = (dia<=20) ? "outono" : "inverno";
            case "setembro" -> estacao = (dia<=20) ? "inverno" : "primavera";
            case "dezembro" -> estacao = (dia<=20) ? "primavera" : "verao";
            case "janeiro", "fevereiro" -> estacao = "Verao";
            case "abril", "junho", "maio" -> estacao = "outono";
            case "agosto" -> estacao = "inverno";
            case "outubro", "novembro" -> estacao = "primavera";
            default -> estacao = "mes inválido";
        }

        System.out.println(estacao);
    }
}
