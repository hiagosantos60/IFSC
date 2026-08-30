package eng.telecom.personagens;

public class Cavaleiro extends Personagem implements Guerreiro{
    private final static int VIDA = 50;
    private final static int ATAQUE = 3;
    private final static double VELOCIDADE = 2; 

    public Cavaleiro(String nome) {
        super(VIDA, ATAQUE, VELOCIDADE, nome);
    }

    @Override
    public String andar() {
        return String.format("Cavaleirio: Estou cavalgando! Velocidade: %d", velocidade);    
    }

    @Override
    public String atacar() {
        return String.format("Cavaleiro: Estou atacando com minha espada! Força: %d", ataque);
    }
}
