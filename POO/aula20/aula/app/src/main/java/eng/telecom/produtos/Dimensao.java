package eng.telecom.produtos;

public class Dimensao {
    private double altura;
    private double largura;
    private double profundidade;

    public Dimensao(double altura, double largura, double profundidade) {
        this.altura = altura;
        this.largura = largura;
        this.profundidade = profundidade;
    }

    @Override
    public String toString() {
        return "Altura = " + altura + ", largura = " + largura + ", profundidade = " + profundidade;
    }

    
}
