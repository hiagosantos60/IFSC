package engtelecom.poo;


public class Veiculo {
    private String modelo;
    private String placa;
    private int anoDeFabricacao;

    public Veiculo(String modelo, String placa, int anoDeFabricacao) {
        this.modelo = modelo;
        this.placa = placa;
        this.anoDeFabricacao = anoDeFabricacao;
    }

    public String getModelo() {
        return modelo;
    }

    public String getPlaca() {
        return placa;
    }

    public int getAnoDeFabricacao() {
        return anoDeFabricacao;
    }

    @Override
    public String toString() {
        return super.toString();
    }
}
