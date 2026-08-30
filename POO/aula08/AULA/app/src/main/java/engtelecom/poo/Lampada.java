package engtelecom.poo;

public class Lampada {
    //Atributos de uma classe
    private boolean ligada = false;

    //# Métodos
    //## Forma não recomendada
    public void ligar() {
        ligada = true;
    }
    public void desligar() {
        ligada = false;
    }

    //## Forma recomendada
    public void ligaDesliga() {
        ligada = !ligada;
    }

    // Conversão para booleano é nomear a função com is...
    public boolean isLigada() {
        return ligada;
    }

}
