package engtelecom.poo;

public class Batedeira {
    private String cor;
    private boolean cheia;
    private boolean fechada;
    private boolean ligada;

    public void setCor(String c) {
        cor = c;
    }
    public String getCor() {
        return cor;
    }

    public void setCheia() {
        cheia = !cheia;
    }
    public boolean getCheia() {
        return cheia;
    }

    public void setAbertaFechada() {
        fechada = !fechada;
    }
    public boolean getAbertaFechada() {
        return fechada;
    }

    public void setLigada() {
        ligada = !ligada;
    }
    public boolean getLigada() {
        return ligada;
    }
}
