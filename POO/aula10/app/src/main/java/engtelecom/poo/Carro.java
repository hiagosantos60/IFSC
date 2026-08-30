package engtelecom.poo;

public class Carro {
    public String modelo;
    private double velocidadeMaxima; 
    private double velocidadeAtual = 0;

    public static final int VELOCIDADE_MAXIMA = 300;
    private static final int VELOCIDADE_MINIMA = 0;


    public Carro(String modelo) {
        this.modelo = modelo;
        this.velocidadeMaxima = VELOCIDADE_MAXIMA;
    }

    public Carro(String modelo, double velocidadeMaxima) {
        this.modelo = modelo;
        this.velocidadeMaxima = velocidadeMaxima;
    }

    public void acelerar(int velocidade) {
        if (velocidade < 0) return;
        
        if ((velocidadeAtual + velocidade) > velocidadeMaxima) this.velocidadeAtual = velocidadeMaxima;

        if ((velocidadeAtual + velocidade) > VELOCIDADE_MAXIMA) velocidadeAtual = VELOCIDADE_MAXIMA;
        else velocidadeAtual += velocidade;
    }

    public void freiar(int velocidade) {
        if (velocidade < VELOCIDADE_MINIMA) return;
        if ((velocidadeAtual - velocidade) < VELOCIDADE_MINIMA) velocidadeAtual = VELOCIDADE_MINIMA;
        else velocidadeAtual -= velocidade;
    }

    public String getModelo() {
        return modelo;
    }

    public double getVelocidadeMaxima() {
        return velocidadeMaxima;
    }

    public double getVelocidadeAtual() {
        return velocidadeAtual;
    }

}
