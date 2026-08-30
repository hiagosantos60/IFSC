package engtelecom.poo;

import java.util.ArrayList;

public class Livro {
    private String titulo;
    private Pessoa autor;
    private ArrayList<Capitulo> livro;

    public Livro(String titulo, Pessoa autor) {
        this.titulo = titulo;
        this.autor = autor;
        this.livro = new ArrayList<>();
    }

    public void adicionarCapitulo(String t) {
        Capitulo cp = new Capitulo(t);
        this.livro.add(cp);
    }

    public void listarCapitulos() {
        for (Capitulo capitulo : livro) {
            System.out.println(capitulo);
        }
    }

    
}
