package engtelecom.poo;

import java.util.ArrayList;

public class Passageiro {
    private String nome;
    private String email;
    private String numeroDeTelefone;
    ArrayList<Reserva> reservas = new ArrayList<>();

    public Passageiro(String nome, String email, String numeroDeTelefone) {
        this.nome = nome;
        this.email = email;
        this.numeroDeTelefone = numeroDeTelefone;
    }

    public boolean addReserva(Reserva r) {
        reservas.add(r);
        return true;
    }

    @Override
    public String toString() {
        return """
           DADOS DO PASSAGEIRO
           Nome: %s
           Email: %s
           Telefone: %s
           """.formatted(nome, email, numeroDeTelefone);
    }
}