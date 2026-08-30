package engtelecom.poo;

public class Usuario {
    private String nome;
    private String email;
    private String cpf;
    private String senha;

    public Usuario(String nome, String email, String senha, String cpf) {
        this.nome = nome;
        this.email = email;
        this.cpf = cpf;
        this.senha = senha;
    }

    public String getNome() {
        return nome;
    }

    public String getEmail() {
        return email;
    }

    public String getCpf(){
        return cpf;
    }

    public boolean avaliarFilme(Filme filme, int nota, String comentario) {
        Avaliacao nova = new Avaliacao(this, filme, nota, comentario);
        return filme.addAvaliacao(nova);
    }

    @Override
    public String toString() {
        return """
                INFORMAÇÕES DO USUÁRIO
                Nome: %s
                Email: %s
                CPF: %d
                """.formatted(nome, email,cpf);
    }
    
}
