package engtelecom.poo;

public class App {
    public static void main(String[] args) {
        Caneta c = new Caneta();

        c.setColor("Preto");
        c.setNivel();
        
        c.setTampada();

        IO.println(c.draw(1,1,2,1));
    }
}
