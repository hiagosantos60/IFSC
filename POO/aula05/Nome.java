void main() {
    // String nome = IO.readln("Entre com seu nome: ");
    // IO.println(nome);
    // // System.out.println("Olá %s", nome);
    // IO.println(String.format("Olá %s", nome)); 

    // //Exercicios:
    int ANO_ATUAL = 2026;

    String nome = IO.readln("Qual seu nome: ");
    String nasc = IO.readln("Qual sua dada de nascimento: ");
    int data_nasc = Integer.parseInt(nasc);
    int idade = ANO_ATUAL - data_nasc;
    IO.println("Olá " + nome + " você tem " + idade + " anos!");
}