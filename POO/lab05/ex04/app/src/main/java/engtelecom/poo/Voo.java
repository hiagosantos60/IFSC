package engtelecom.poo;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.ArrayList;

public class Voo {
    private static int cont = 0;
    private int numeroDoVoo;
    private String destino;
    private LocalDate data;
    private LocalDateTime horaDePartida;
    private int capacidadeMaxima;
    ArrayList<Reserva> reservas = new ArrayList<>();

    public Voo(String destino, LocalDate data, LocalDateTime horaDePartida, int capacidadeMaxima) {
        this.numeroDoVoo = ++cont;
        this.destino = destino;
        this.data = data;
        this.horaDePartida = horaDePartida;
        this.capacidadeMaxima = capacidadeMaxima;
    }

    public boolean addReserva(Reserva r) {
        reservas.add(r);
        return true;
    }

    public static int getCont() {
        return cont;
    }

    public int getNumeroDoVoo() {
        return numeroDoVoo;
    }

    public String getDestino() {
        return destino;
    }

    public LocalDate getData() {
        return data;
    }

    public LocalDateTime getHoraDePartida() {
        return horaDePartida;
    }

    public int getCapacidadeMaxima() {
        return capacidadeMaxima;
    }

    @Override
    public String toString() {
        return "Voo #" + numeroDoVoo + " | Destino: " + destino + 
           " | Data: " + data + " | Partida: " + horaDePartida.toLocalTime() + 
           " | Cap: " + capacidadeMaxima;
    }
    
}
