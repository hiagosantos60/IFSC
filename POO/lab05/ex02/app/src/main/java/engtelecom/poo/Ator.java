package engtelecom.poo;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Ator {
    private String nome;
    private LocalDate dataNascimento;

    public Ator(String nome, LocalDate dataNascimento) {
        this.nome = nome;
        this.dataNascimento = dataNascimento;
    }

    public String getNome() {
        return nome;
    }

    public LocalDate getDataNascimento() {
        return dataNascimento;
    }
    
    @Override
    public String toString() {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");

        return """
                INFORMACAO DO ATOR
                Nome: %s
                Data de Nascimento: %s
                """.formatted(nome, dataNascimento.format(formatter));
    }
}
