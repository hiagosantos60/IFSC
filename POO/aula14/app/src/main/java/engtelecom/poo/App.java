
package engtelecom.poo;

public class App {
    public static void main(String[] args) {
        // Motor mo = new Motor(10, 4);
        // Carro c = new Carro("ford", mo);
    
        // c.acelerar(10);
        // System.out.println(mo.getGiroAtual());

        Pessoa p = new Pessoa("hiago");
        Livro l = new Livro("aaa", p);
        l.adicionarCapitulo("A noite de um homem triste");
        l.adicionarCapitulo("O dia de um homem feliz");
        l.listarCapitulos();
    }
}
