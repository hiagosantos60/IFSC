package engtelecom.poo.ex02;

public enum Valor {
    AS(1,"Ás"), 
    DOIS(2, "Dois"),
    TRES(3, "Três"),
    QUATRO(4, "Quatro"),
    CINCO(5, "Cinco"),
    SEIS(6, "Seis"),
    SETE(7, "Sete"),
    OITO(8, "Oito"),
    NOVE(9, "Nove"),
    DAMA(10, "Dama"), 
    VALETE(11, "Valete"), 
    REI(12, "Rei");

    public final int valor;
    public final String extenso;

    private Valor(int valor, String extenso) {
        this.valor = valor;
        this.extenso = extenso;
    }

    public static Valor getByValor(int v) {
        for (Valor n : Valor.values()) {
            if(n.valor == v){
                return n;
            }
        }

        throw new IllegalArgumentException("Código inválido");
    }

    @Override
    public String toString() {
        return extenso;
    }
}
