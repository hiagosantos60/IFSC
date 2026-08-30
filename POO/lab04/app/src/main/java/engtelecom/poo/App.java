package engtelecom.poo;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class App {
    private void menu() {
        System.out.println("");
        System.out.println("Adicionar contato - [1]");
        System.out.println("Remover contato - [2]");
        System.out.println("Adicionar email - [3]");
        System.out.println("Remover email - [4]");
        System.out.println("Atualizar email - [5]");
        System.out.println("Adicionar telefone - [6]");
        System.out.println("Remover telefone - [7]");
        System.out.println("Listar todos os contatos - [8]");
        System.out.println("Sair - [0]");
        System.out.println("");
    }

    private int op;

    public void main() {
        App app = new App();
        AgendaTelefonica agenda = new AgendaTelefonica();

        System.out.println("=== Agenda de contatos ===");

        do {
            app.menu();
            
            op = Integer.parseInt(IO.readln("O que deseja fazer: "));

            switch (op) {
                case 1: // adicionar contato
                    getOP1(agenda);
                    break;
                
                case 2: //
                    getOP2(agenda);
                    break;

                case 3: // adicionar email um contato 
                    getOP3(agenda);
                    break;

                case 4: // remover email em um contato
                    getOP4(agenda);
                    break;

                case 5: // atualizar email de um contato
                    getOP5(agenda);
                    break;

                case 6: // adicionar telefone
                    getOP6(agenda);
                    break;
                
                case 7: // remover telefone
                    getOP7(agenda);

                    break;
                
                case 8: // listar todas as informações
                    agenda.listaContatos();
                    break;
                default:
                    break;
            }

        } while (op != 0);


    }

    private void getOP7(AgendaTelefonica agenda) {
        int idContato = Integer.parseInt(IO.readln("Qual o id do contato que deseja remover um telefone: "));
        int idTelefone = Integer.parseInt(IO.readln("Qual o id do telefone que você deseja remover: "));
        agenda.removeTelefone(idTelefone, idContato);
    }

    private void getOP6(AgendaTelefonica agenda) {
        int idContato = Integer.parseInt(IO.readln("Qual o id do contato que deseja adicionar um telefone: "));
        String valor = IO.readln("Qual o número de telefone: ");
        String rotulo = IO.readln("Qual o rótulo para esse telefone: ");
        if(agenda.addTelefone(rotulo, valor, idContato)) System.out.println("Adicionado com sucesso! ");
    }

    private void getOP5(AgendaTelefonica agenda) {
        int idContato = Integer.parseInt(IO.readln("Qual o id do contato que deseja atualizar o email: "));
        int idEmail = Integer.parseInt(IO.readln("Qual o id do email: "));
        String valor = IO.readln("Qual o novo domínio do email: ");
        String rotulo = IO.readln("Qual o novo rótulo para esse email: ");
        if(agenda.updateEmail(rotulo, valor, idContato, idEmail)) System.out.println("Atualizado com sucesso!");
        else System.out.println("Não foi possíve atualizar email.");
    }

    private void getOP4(AgendaTelefonica agenda) {
        int idContato = Integer.parseInt(IO.readln("Qual o id do contato que deseja remover um email: "));
        int idEmail = Integer.parseInt(IO.readln("Qual o id do email: "));
        if(agenda.removeEmail(idEmail, idContato)) System.out.println("Removido com sucesso!");
        else System.out.println("Não foi possivel remover contato.");
    }

    private void getOP3(AgendaTelefonica agenda) {
        int idContato = Integer.parseInt(IO.readln("Qual o id do contato que deseja adicionar um email: "));
        String valor = IO.readln("Qual o domínio do email: ");
        String rotulo = IO.readln("Qual o rótulo para esse email: ");
        if (agenda.addEmail(rotulo, valor, idContato)) System.out.println("Adicionado com sucesso!");
        else System.out.println("Não foi possível adicionar email.");
    }

    private void getOP2(AgendaTelefonica agenda) {
        int idContato = Integer.parseInt(IO.readln("Qual o id do contato que deseja remover: "));
        if(agenda.removeContato(idContato)) System.out.println("Removido com sucesso! ");
        else System.out.println("Não foi possível remover contato.");
    }

    private void getOP1(AgendaTelefonica agenda) {
        String n = IO.readln("Qual o nome: ");
        String sb = IO.readln("Qual o sobrenome: ");
        String nascimento = IO.readln("Qual a data de nascimento: ");

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        LocalDate dn = LocalDate.parse(nascimento, formatter);

        Contato c = new Contato(n, sb, dn);
        if(agenda.addContato(c)) System.out.println("Adicionado com sucesso!");
        else System.out.println("Não foi possível adicionar o contato.");
    }
}