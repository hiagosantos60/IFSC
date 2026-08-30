package engtelecom.poo;

import java.time.LocalDate;

public class App {
    public static void main(String[] args) {
        // --- CADASTRO DE DIRETORES E ATORES ---
        Diretor nolan = new Diretor("Christopher Nolan", LocalDate.of(1970, 7, 30));
        Diretor greta = new Diretor("Greta Gerwig", LocalDate.of(1983, 8, 4));

        Ator murphy = new Ator("Cillian Murphy", LocalDate.of(1976, 5, 25));
        Ator gosling = new Ator("Ryan Gosling", LocalDate.of(1980, 11, 12));
        Ator robbie = new Ator("Margot Robbie", LocalDate.of(1990, 7, 2));

        // --- CADASTRO DE FILMES ---
        Filme f1 = new Filme("Oppenheimer", 2023, "Drama", nolan);
        f1.addAtor(murphy);

        Filme f2 = new Filme("Barbie", 2023, "Comédia", greta);
        f2.addAtor(robbie);
        f2.addAtor(gosling);

        Filme f3 = new Filme("Interestelar", 2014, "Sci-Fi", nolan);
        // (Atores de Interestelar poderiam ser adicionados aqui)

        // --- CADASTRO DE USUÁRIOS ---
        Usuario u1 = new Usuario("Hiago", "hiago@ifsc.edu.br", "senha123", "11122233344");
        Usuario u2 = new Usuario("Ana", "ana@gmail.com", "ana2024", "55566677788");
        Usuario u3 = new Usuario("Carlos", "carlos@outlook.com", "carlos123", "99900011122");

        // --- FLUXO DE AVALIAÇÕES ---
        
        // Filme 1: Oppenheimer (Média esperada: 4.5)
        f1.addAvaliacao(new Avaliacao(u1, f1, 5, "Incrível!"));
        f1.addAvaliacao(new Avaliacao(u2, f1, 4, "Muito bom, mas denso."));

        // Filme 2: Barbie (Média esperada: 4.0)
        f2.addAvaliacao(new Avaliacao(u1, f2, 4, "Divertido."));
        f2.addAvaliacao(new Avaliacao(u2, f2, 5, "Melhor do ano!"));
        f2.addAvaliacao(new Avaliacao(u3, f2, 3, "Legal, mas esperava mais."));

        // Filme 3: Interestelar (Ainda sem notas)
        
        // --- EXIBIÇÃO DOS RESULTADOS ---
        System.out.println(f1);
        System.out.println(f2);
        System.out.println(f3);

        // TESTE DE SEGURANÇA: Hiago tentando avaliar Barbie de novo
        boolean tentouDeNovo = f2.addAvaliacao(new Avaliacao(u1, f2, 1, "Mudei de ideia"));
        System.out.println("Hiago avaliou Barbie de novo? " + tentouDeNovo); // Deve ser false
    }
}