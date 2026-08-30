package engtelecom.poo;

// implementação simples de conta com array list

import java.util.ArrayList;

public class App {

    private ArrayList<Conta> contas = new ArrayList<>();

    public static void exibirMenu() {
        System.out.println("\n--- MENU ---");
        System.out.println("1 - Criar conta");
        System.out.println("2 - Listar todas as contas");
        System.out.println("3 - Sacar");
        System.out.println("4 - Depositar");
        System.out.println("5 - Sair");
    }

    public void executarMenu(int opcao) {
        switch (opcao) {
            case 1:
                String n = IO.readln("Entre com o nome: ");
                double s = Double.parseDouble(IO.readln("Entre com o saldo inicial: "));
                long num = Long.parseLong(IO.readln("Entre com número da conta: "));
                Conta user = new Conta(num, s, n);
                contas.add(user);
                break;
            case 2:
                contas.forEach(IO::println);
                break;
            case 3:
                long c = Long.parseLong(IO.readln("Qual o número da conta: "));
                double v = Double.parseDouble(IO.readln("Quanto deseja sacar: "));

                // contas.forEach(e -> {
                //     if(e.getNumConta() == c) {
                //         e.sacar(v);
                //     } else {
                //         System.out.println("Conta não encontrada...");
                //     }
                // });

                for (Conta e : this.contas) {
                    if(e.getNumConta() == c){
                        e.sacar(v);
                        break;
                    }
                }
                
                break;
            case 4:
                c = Long.parseLong(IO.readln("Qual o número da conta: "));
                v = Double.parseDouble(IO.readln("Quanto deseja depositar: "));
                contas.forEach(e -> {
                    if(e.getNumConta() == c){
                        e.depositar(v);
                    } else {
                        System.out.println("Conta não encontrada...");
                    }
                });

                break;
            default:
                System.out.println("Opção inválida!");
                break;
        }
    }

    public static void main(String[] args) {
        App app = new App();
        int opcao = 0;

        while (opcao != 5) {
            exibirMenu();

            opcao = Integer.parseInt(IO.readln("O que deseja fazer? "));

            if (opcao != 5) {
                app.executarMenu(opcao);
            }
        }

        System.out.println("Programa encerrado.");
    }
}