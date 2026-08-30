package eng.telecom.personagens;

public abstract class Personagem {
    protected int vida;
    protected int ataque;
    protected double velocidade;
    protected String identificacao;

    public Personagem(int vida, int ataque, double velocidade, String identificacao) {
        this.vida = vida;
        this.ataque = ataque;
        this.velocidade = velocidade;
        this.identificacao = identificacao;
    }

    public abstract String andar(); 

    @Override
    public String toString() {
        return "Personagem [vida=" + vida + ", ataque=" + ataque + ", velocidade=" + velocidade + ", identificacao="
                + identificacao + "]";
    }
}
