package engtelecom.poo;

import java.time.LocalDateTime;

public class Reserva {
    private String codigoReserva;
    private int numeroAssentos;
    private LocalDateTime dataCriacao;
    private Passageiro passageiro;
    private Voo voo;
    
    public Reserva(String codigoReserva, int numeroAssentos, LocalDateTime dataCriacao, Passageiro passageiro,
            Voo voo) {
        this.codigoReserva = codigoReserva;
        this.numeroAssentos = numeroAssentos;
        this.dataCriacao = dataCriacao;
        this.passageiro = passageiro;
        this.voo = voo;
    }

    public String getCodigoReserva() {
        return codigoReserva;
    }

    public int getNumeroAssentos() {
        return numeroAssentos;
    }

    public LocalDateTime getDataCriacao() {
        return dataCriacao;
    }

    public Passageiro getPassageiro() {
        return passageiro;
    }

    public Voo getVoo() {
        return voo;
    }

    
}
