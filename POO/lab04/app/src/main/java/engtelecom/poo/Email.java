package engtelecom.poo;

public class Email {
    private String rotulo;
    private String valor;

    public Email(String rotulo, String valor) {
        this.rotulo = rotulo;
        this.valor = valor;
    }

    public String getRotulo() {
        return rotulo;
    }

    public String getValor() {
        return valor;
    }

    public void setRotulo(String rotulo) {
        this.rotulo = rotulo;
    }

    public void setValor(String valor) {
        this.valor = valor;
    }

    @Override
    public String toString() {
        return rotulo + ": " + valor;
    }
}