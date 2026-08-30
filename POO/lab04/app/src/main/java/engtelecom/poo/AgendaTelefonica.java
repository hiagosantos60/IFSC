package engtelecom.poo;

import java.time.LocalDate;
import java.util.ArrayList;

public class AgendaTelefonica {

    private ArrayList<Contato> contatos = new ArrayList<>();

    public Contato findContato(String nome, String sobrenome, LocalDate dataNasc) {
        for (Contato c : contatos) {
            if (c.getNome().equalsIgnoreCase(nome) && c.getSobrenome().equalsIgnoreCase(sobrenome) && c.getDataNasc().equals(dataNasc)) {
                return c;
            }
        }
        return null;
    }

    private boolean isValido(int indice) {
        return indice >= 0 && indice < contatos.size();
    }

    public boolean addContato(Contato c) {
        if (c == null) return false;

        if (findContato(c.getNome(), c.getSobrenome(), c.getDataNasc()) != null) {
            return false;
        }

        contatos.add(c);
        return true;
    }

    public boolean removeContato(int indiceContato) {
        if (!isValido(indiceContato)) return false;

        contatos.remove(indiceContato);
        return true;
    }

    public boolean addEmail(String rotulo, String valor, int indiceContato) {
        if (!isValido(indiceContato)) return false;

        return contatos.get(indiceContato).addEmail(rotulo, valor);
    }

    public boolean removeEmail(int indiceEmail, int indiceContato) {
        if (!isValido(indiceContato)) return false;

        return contatos.get(indiceContato).removeEmail(indiceEmail);
    }

    public boolean updateEmail(String rotulo, String valor, int indiceContato, int indiceEmail) {
        if (!isValido(indiceContato)) return false;

        return contatos.get(indiceContato).updateEmail(indiceEmail, rotulo, valor);
    }


    public boolean addTelefone(String rotulo, String valor, int indiceContato) {
        if (!isValido(indiceContato)) return false;

        return contatos.get(indiceContato).addTelefone(rotulo, valor);
    }

    public boolean removeTelefone(int indiceTelefone, int indiceContato) {
        if (!isValido(indiceContato)) return false;

        return contatos.get(indiceContato).removeTelefone(indiceTelefone);
    }

    public boolean updateTelefone(String rotulo, String valor, int indiceContato, int indiceTelefone) {
        if (!isValido(indiceContato)) return false;

        return contatos.get(indiceContato).updateTelefone(indiceTelefone, rotulo, valor);
    }

    public void listaContatos() {
        if (contatos.isEmpty()) {
            System.out.println("Nenhum contato cadastrado.");
            return;
        }

        for (int i = 0; i < contatos.size(); i++) {
            System.out.println("=================================");
            System.out.println("Contato #" + i);
            System.out.println(contatos.get(i));
        }
    }
}