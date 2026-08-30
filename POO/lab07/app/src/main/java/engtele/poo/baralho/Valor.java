package engtele.poo.baralho;

public enum Valor {
    AS(1,"Ás", "1"), 
    DOIS(2, "Dois", "2"),
    TRES(3, "Três", "3"),
    QUATRO(4, "Quatro", "4"),
    CINCO(5, "Cinco", "5"),
    SEIS(6, "Seis", "6"),
    SETE(7, "Sete", "7"),
    OITO(8, "Oito", "8"),
    NOVE(9, "Nove","9"),
    DEZ(10,"Dez", "10"),
    DAMA(11, "Dama","q"), 
    VALETE(12, "Valete", "k"), 
    REI(13, "Rei", "j");

    public final int valor;
    public final String extenso;
    public final String inicial;

    private Valor(int valor, String extenso, String inicial) {
        this.valor = valor;
        this.extenso = extenso;
        this.inicial = inicial;
    }

    public static Valor getByValor(int v) {
        for (Valor n : Valor.values()) {
            if(n.valor == v){
                return n;
            }
        }

        throw new IllegalArgumentException("Código inválido");
    }

    public int getValor() {
        return valor;
    }

    public String getExtenso() {
        return extenso;
    }

    public String getInicial() {
        return inicial;
    }

    @Override
    public String toString() {
        return extenso;
    }
}
