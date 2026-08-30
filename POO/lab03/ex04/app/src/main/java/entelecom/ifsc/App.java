package entelecom.ifsc;

public class App {
    public static void main(String[] args) {
        Data d = new Data(10, 3, 2000);
        Data b = new Data(10, 4, 2000);
    
        IO.println(d.porExtenso());
        IO.println(b.porExtenso());

        IO.println(d.calcularDiferenca(b));
    }
}
