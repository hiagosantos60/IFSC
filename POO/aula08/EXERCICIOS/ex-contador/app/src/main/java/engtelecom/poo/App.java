package engtelecom.poo;

public class App {
    public static void main(String[] args) {
    
        //Exemplos de uso para o Contador
        Contador c = new Contador();
        c.setValor(50);
        IO.println(c.getValor());
        c.incrementar();
        IO.println(c.getValor());



        }
}
