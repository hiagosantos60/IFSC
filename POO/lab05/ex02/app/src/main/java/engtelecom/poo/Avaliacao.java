package engtelecom.poo;

public class Avaliacao {
    private static int cont = 0;
    private int idAvalicao;
    private Usuario usuario;
    private Filme filme;
    private int nota;
    private String comentario;
    
    public Avaliacao(Usuario usuario, Filme filme, int nota, String comentario) {
        this.usuario = usuario;
        this.filme = filme;
        if(nota < 0) {
            this.nota = 0;
        } else if(nota > 5) {
            this.nota = 5;
        } else {
            this.nota = nota;
        }
        this.comentario = comentario;
        this.idAvalicao = ++cont;
    }

    public int getIdAvalicao() {
        return idAvalicao;
    }

    public Usuario getUsuario() {
        return usuario;
    }

    public Filme getFilme() {
        return filme;
    }

    public int getNota() {
        return nota;
    }

    public String getComentario() {
        return comentario;
    }
    
    @Override
    public String toString() {
        return """
                INFORMAÇÕES DA AVALIAÇÃO:
                ID da avaliação: %d
                Usuario: %s
                Filme: %s
                Nota: %d
                Comentario: %s
                """.formatted(idAvalicao,usuario,filme,nota,comentario);
    }
}
