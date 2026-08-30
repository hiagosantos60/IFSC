package engtelecom.poo;

public class Livro {
    private final String iSBN;
    private String titulo;
    private String autor;
    private int ano;

    public Livro(String iSBN, String titulo, String autor, int ano) {
        this.iSBN = iSBN;
        this.titulo = titulo;
        this.autor = autor;
        this.ano = ano;
    }

    public String toString() {
        return String.format("""
                ==Livro==
                ISBN: %s
                Titulo: %s
                Autor: %s
                Ano: %s
                """, iSBN,titulo,autor,ano);
    }

   public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public String getiSBN() {
        return iSBN;
    }

    public String getTitulo() {
        return titulo;
    }

    public String getAutor() {
        return autor;
    }

    public int getAno() {
        return ano;
    }
}
