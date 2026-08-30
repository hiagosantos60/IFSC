package eng.telecom.personagens;

public class Arqueiro extends Personagem implements Guerreiro{

    private final static int VIDA = 35;
    private final static int ATAQUE = 2;
    private final static double VELOCIDADE = 1; 

    public Arqueiro(String nome) {
        super(VIDA, ATAQUE, VELOCIDADE, nome);
    }

    @Override
    public String andar() {
        return String.format("Arqueiro: Estou correndo muito! Velocidade: %d", velocidade);
    }

    @Override
    public String atacar() {
        return String.format("Arqueiro: Estou atacando com meu arco! Força: %d", ataque);
    }
}
