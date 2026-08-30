package engtelecom.poo;

import java.time.LocalDate;

public class Registro {
    private Veiculo veiculo;
    private Motorista motorista;
    private LocalDate data;
    private double distancia;
    
    public Registro(Veiculo veiculo, Motorista motorista, LocalDate data, double distancia) {
        this.veiculo = veiculo;
        this.motorista = motorista;
        this.data = data;
        this.distancia = distancia;
    }

    public Veiculo getVeiculo() {
        return veiculo;
    }

    public Motorista getMotorista() {
        return motorista;
    }

    public LocalDate getData() {
        return data;
    }

    public double getDistancia() {
        return distancia;
    }

    @Override
    public String toString() {
        return super.toString();
    }
}
