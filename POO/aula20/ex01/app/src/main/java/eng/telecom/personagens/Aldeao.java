package eng.telecom.personagens;

public class Aldeao extends Personagem implements Guerreiro, Coletor {

    private final static int VIDA = 25;
    private final static int ATAQUE = 1;
    private final static double VELOCIDADE = 0.8; 

    public Aldeao(String nome) {
        super(VIDA, ATAQUE, VELOCIDADE, nome);
    }

    @Override
    public String andar() {
        return "Aldeao: Estou andando calmamente...";
    }

    @Override
    public String atacar() {
        return String.format("Aldeao: Estou atacando com uma picareta e força %d", ataque);
    }

    @Override
    public String coletarMadeira() {
        return "Aldeão: Estou coletando madeira";
    }

    @Override
    public String coletarOuro() {
        return "Aldeão: Estou coletando ouro";
    }
    
    
}
