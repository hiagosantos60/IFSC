package engtelecom.poo;

public class Robo {
    private String nome;
    private long ns;
    private static long totalRobos;
    
    public Robo(String nome) {
        this.nome = nome;
        ns = totalRobos + 1;
        totalRobos++;
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getNome() {
        return nome;
    }

    @Override
    public String toString() {
        return nome;
    }

    
}
