package engtelecom.poo.ex02;


public enum Naipes {
    OUROS("Ouro", 1), 
    ESPADAS("Espadas", 2), 
    COPAS("Copas", 3),
    PAUS("Paus", 4); 

    public final String nome;
    public final int valor;

    private Naipes(String nome, int valor) {
        this.nome = nome;
        this.valor = valor;
    }

    public static Naipes getByValor(int c) {
        for (Naipes n : Naipes.values()) {
            if(n.valor == c) {
                return n;
            }
        }

        throw new IllegalArgumentException("Código inválido");
    }

    @Override
    public String toString() {
        return nome;
    }
    
}
