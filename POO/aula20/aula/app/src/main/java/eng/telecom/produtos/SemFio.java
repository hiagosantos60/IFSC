package eng.telecom.produtos;

public class SemFio extends Telefone {
    private double frequencia;
    private int canais;
    private double distanciaOperacao;

    public SemFio(int codigo, String numSerie, String modelo, double peso, Dimensao dimensao, double frequencia,
            int canais, double distanciaOperacao) {
        super(codigo, numSerie, modelo, peso, dimensao);
        this.frequencia = frequencia;
        this.canais = canais;
        this.distanciaOperacao = distanciaOperacao;
        this.modelo = "teste";
    }

    public double getFrequencia() {
        return frequencia;
    }

    // @Override
    public String toString() {
        return super.toString() + " " + "SemFio [frequencia=" + frequencia + ", canais=" + canais + ", distanciaOperacao=" + distanciaOperacao + "]";
    }
}


