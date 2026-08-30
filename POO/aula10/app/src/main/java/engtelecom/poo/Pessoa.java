package engtelecom.poo;

public class Pessoa {
    private String nome;
    private String cpf;
    private String email;


    public Pessoa(String nome, String cpf, String email) {
        this.nome = nome;
        this.cpf = cpf;
        this.email = email;
    }

    @Override
    public String toString() {
        return String.format("O nome: %s\nCPF: %s \nEmail: %s", nome, cpf, email);
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpf() {
        return cpf;
    }

    public String getEmail() {
        return this.email;
    }

    public String getNome() {
        return nome;
    }
}
