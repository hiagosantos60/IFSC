package engtelecom.poo;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Diretor {
    private String nome;
    private LocalDate dataDeNascimento;
    
    public Diretor(String nome, LocalDate dataDeNascimento) {
        this.nome = nome;
        this.dataDeNascimento = dataDeNascimento;
    }

    public String getNome() {
        return nome;
    }

    public LocalDate getDataDeNascimento() {
        return dataDeNascimento;
    }

    @Override
    public String toString() {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        return """
                INFORMAÇÕES DO DIRETOR
                Nome: %s
                Data de Nascimento: %s
                """.formatted(nome, dataDeNascimento.format(formatter));
    }
}
