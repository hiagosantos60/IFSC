package engtelecom.poo;

public class Personagem {
    private String nome;
    private double vida = 100;
    private int nivel = 1;

    public String getNome() {
        return nome;
    }

    public double getVida() {
        return vida;
    }

    public int getNivel() {
        return nivel;
    }

    public void setNome(String n) {
        nome = n;
    }

    public void setVida(double v) {
        if (v < 0) {
            vida = 0;
        } else if (v > 100) {
            vida = 100;
        } else {
            vida = v;
        }
    }

    public void levelUp() {
        nivel++;
    }
}