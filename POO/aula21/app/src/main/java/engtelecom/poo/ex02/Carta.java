package engtelecom.poo.ex02;

public class Carta {
    Naipes naipe;
    Valor valor;

    public Carta(Naipes naipe, Valor valor) {
        this.naipe = naipe;
        this.valor = valor;
    }

    @Override
    public String toString(){
        return String.format("""
                %s de %s
                """, valor, naipe);
    }
}
