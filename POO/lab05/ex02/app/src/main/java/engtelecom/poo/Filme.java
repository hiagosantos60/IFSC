package engtelecom.poo;

import java.util.ArrayList;

public class Filme {
    private static int cont = 0;
    private int idFilme;
    private String titulo;
    private int anoDeLancamento;
    private String genero;
    private Diretor diretor;
    private ArrayList<Ator> atores = new ArrayList<>();
    private ArrayList<Avaliacao> avaliacoes = new ArrayList<>();

    public Filme(String titulo, int anoDeLancamento, String genero, Diretor diretor) {
        this.titulo = titulo;
        this.anoDeLancamento = anoDeLancamento;
        this.genero = genero;
        this.diretor = diretor;
        this.idFilme = ++cont;
    }

    public boolean addAvaliacao(Avaliacao NovaAvaliacao) {
        for (Avaliacao a : avaliacoes) { // caso aquele usuário já ter avaliado o filme
            if(a.getUsuario().getCpf().equals(NovaAvaliacao.getUsuario().getCpf())){
                return false;
            }
        }

        avaliacoes.add(NovaAvaliacao);
        return true;
    }

    public float getMediaAvaliacoes(){
        if(avaliacoes.isEmpty()) return 0;

        float i=0;
        float totalValorNotas=0;
        for (Avaliacao a : avaliacoes) {
            totalValorNotas += a.getNota();
            i++;
        }

        return totalValorNotas/i;
    }

    public boolean addAtor(Ator ator) {
        if(atores.contains(ator)) return false;
        atores.add(ator);
        return true;
    }

    public int getIdFilme() {
        return idFilme;
    }

    public String getTitulo() {
        return titulo;
    }

    public int getAnoDeLancamento() {
        return anoDeLancamento;
    }

    public String getGenero() {
        return genero;
    }

    public Diretor getDiretor() {
        return diretor;
    }

    @Override
public String toString() {

    String nomesAtores = "";
    for (int i = 0; i < atores.size(); i++) {
        nomesAtores += atores.get(i).getNome();
        if (i < atores.size() - 1) {
            nomesAtores += ", ";
        }
    }

    if (atores.isEmpty()) nomesAtores = "Nenhum ator cadastrado";

    return """
    === INFORMACOES DO FILME ===
    [%d] %s (%d)
    Gênero: %s | Diretor: %s
    Média: %.1f (%d avaliações)
    Elenco: %s
    ============================
    """.formatted(
        idFilme, 
        titulo, 
        anoDeLancamento, 
        genero, 
        diretor.getNome(), 
        getMediaAvaliacoes(), 
        avaliacoes.size(),
        nomesAtores // Usamos a String formatada aqui
    );
}
    
}
