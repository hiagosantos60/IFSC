package engtele.poo.baralho;


public enum Naipes {
    OUROS("Ouro", 1, 'o'), 
    ESPADAS("Espadas", 2, 'e'), 
    COPAS("Copas", 3, 'c'),
    PAUS("Paus", 4 , 'p'); 

    public final String nome;
    public final int valor;
    public final char inicial;

    private Naipes(String nome, int valor, char inicial) {
        this.nome = nome;
        this.valor = valor;
        this.inicial = inicial;
    }

    public static Naipes getByValor(int c) {
        for (Naipes n : Naipes.values()) {
            if(n.valor == c) {
                return n;
            }
        }

        throw new IllegalArgumentException("Código inválido");
    }

    public String getNome() {
        return nome;
    }

    public int getValor() {
        return valor;
    }

    public char getInicial() {
        return inicial;
    }

    @Override
    public String toString() {
        return nome;
    }
    
}
