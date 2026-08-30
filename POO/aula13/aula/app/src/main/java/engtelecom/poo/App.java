package engtelecom.poo;

import java.util.HashMap;

public class App {

    HashMap<String, Livro> acervo = new HashMap<>();

     public void exibirMenu() {
        System.out.println("\n--- MENU ---");
        System.out.println("1 - Cadastrar livro");
        System.out.println("2 - Listar iSBN e imprimir todos os livros");
        System.out.println("3 - Consultar por iSBN e imprimir todos os livros");
        System.out.println("4 - Consultar livro por autor e imprimir os dados do livro");
        System.out.println("5 - Atualizar dados de um livro, exceto o iSBN");
        System.out.println("6 - Remover livro pelo iSBN ");
        System.out.println("7 - Sair");
    }

    public void executarMenu(int opcao) {
        switch (opcao) {
            case 1:
                String iSBN = IO.readln("Entre com o iSBN: ");
                String titulo = IO.readln("Entre com o título do livro: ");
                String autor = IO.readln("Entre com o nome do autor: ");
                int ano = Integer.parseInt(IO.readln("Entre com a data de lançamento do livro: "));
                cadastrarLivro(iSBN, titulo, autor, ano);
                break;
            case 2:
                listarLivros();
                break;
            case 3:
                iSBN = IO.readln("Entre com o iSBN: ");
                consultarPorISBN(iSBN);
                break;
            case 4:
                autor = IO.readln("Qual o nome do autor: ").toLowerCase();
                consultarPorNome(autor);
                break;
            case 5:
                atualizarLivro();
                break;
            case 6:
                String ISBN = IO.readln("Qual o ISBN do livro que deseja remover: ");
                removerPorISBN(ISBN);
                break;
            default:
                System.out.println("Opção inválida!");
                break;
        }
    }

    private void cadastrarLivro(String iSBN, String titulo, String autor, int ano) {
        if (!acervo.containsKey(iSBN)) {
            Livro v = new Livro(iSBN, titulo, autor, ano);
            acervo.put(iSBN, v);
        } else String.format("Livro já cadastrado...\n");
    }

    private void listarLivros() {
        for(Livro livro: acervo.values()){
            System.out.println(livro);
        }
    }

    private void consultarPorISBN(String iSBN) {
        if(acervo.containsKey(iSBN)){
            System.out.println(acervo.get(iSBN));
        }
    }

    private void consultarPorNome(String autor) {
        for (Livro livro : acervo.values()) {
            if(livro.getAutor().toLowerCase().contains(autor)){
                System.out.println(livro);
            }
        }
    }

    private void atualizarLivro() {
        String isbn = IO.readln("Qual o ISBN que deseja atualizar: ");
        System.out.println("Menu de atualização");
        System.out.println("1 - Titulo:");
        System.out.println("2 - Autor");
        System.out.println("3 - Ano de publicação");
        int opcao = Integer.parseInt(IO.readln("O que deseja atualizar: "));

        Livro livro = acervo.get(isbn);

        switch (opcao) {
        case 1:
            String novoTitulo = IO.readln("Qual o novo título: ");
            livro.setTitulo(novoTitulo);
            break;
        case 2:
            String novoAutor = IO.readln("Qual o novo autor: ");
            livro.setAutor(novoAutor);
            break;
        case 3:
            int novoAno = Integer.parseInt(IO.readln("Qual o novo ano: "));
            livro.setAno(novoAno); // Use o setAno e converta para int
            break;
        default:
            System.out.println("Opção inválida.");
            break;
    }
    }

    public void removerPorISBN(String ISBN){
        if(acervo.containsKey(ISBN)) {
            acervo.remove(ISBN);
        }
    }

    public static void main(String[] args) {

        /*
        1 - Cadastrar livro
        2 - Listar ISBN e título de todos os livros
        3 - Consultar por ISBN e imprimir todos os livros
        4 - Consultar livro por autor e imprimir os dados do livro
        5 - Atualizar dados de um livro, exceto o ISBN
        6 - Remover livro pelo ISBN 
        7 - Sair
        */
        
        App app = new App();
        int opcao = 0; 

        while (opcao!=7) {
            app.exibirMenu();
            opcao = Integer.parseInt(IO.readln("O que deseja fazer: "));
            if(opcao != 7){
                app.executarMenu(opcao);
            } 
        }
    }
}
