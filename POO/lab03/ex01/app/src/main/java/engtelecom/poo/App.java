package engtelecom.poo;

public class App {
    public static void main(String[] args) {
        Ponto a = new Ponto(3, 4);
        Ponto b = new Ponto(0, 0);

        IO.println(a.calcularDistancia(b));

        IO.println(a);
    }
}
