package engtelecom.poo;

import java.text.ParseException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

import javax.swing.text.MaskFormatter;

public class Contato {
    private ArrayList<Email> emails = new ArrayList<>();
    private ArrayList<Telefone> telefones = new ArrayList<>();
    private String nome;
    private String sobrenome;
    private LocalDate dataNasc;

    public Contato(String nome, String sobrenome, LocalDate dataNasc) {
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.dataNasc = dataNasc;
    }

    public boolean validarEmail(String valor) {
        String regex = "^[\\w-\\+]+(\\.[\\w]+)*@[\\w-]+(\\.[\\w]+)*(\\.[a-z]{2,})$";
        return valor != null && valor.matches(regex);
    }

    public boolean validarTelefone(String valor) {
        String regex = "^[1-9]{2}(9[0-9]{8}|[2-5][0-9]{7})$";
        return valor != null && valor.matches(regex);
    }

    public boolean addEmail(String rotulo, String valor) {
        if (!validarEmail(valor))
            return false;

        emails.add(new Email(rotulo, valor));
        return true;
    }

    public boolean removeEmail(int indiceEmail) {
        if (indiceEmail < 0 || indiceEmail >= emails.size())
            return false;

        emails.remove(indiceEmail);
        return true;
    }

    public boolean updateEmail(int indiceEmail, String rotulo, String valor) {
        if (indiceEmail < 0 || indiceEmail >= emails.size())
            return false;
        if (!validarEmail(valor))
            return false;

        Email e = emails.get(indiceEmail);
        e.setRotulo(rotulo);
        e.setValor(valor);

        return true;
    }

    public boolean addTelefone(String rotulo, String valor) {
        if (!validarTelefone(valor))
            return false;

        telefones.add(new Telefone(rotulo, valor));
        return true;
    }

    public boolean removeTelefone(int indiceTelefone) {
        if (indiceTelefone < 0 || indiceTelefone >= telefones.size())
            return false;

        telefones.remove(indiceTelefone);
        return true;
    }

    public boolean updateTelefone(int indiceTelefone, String rotulo, String valor) {
        if (indiceTelefone < 0 || indiceTelefone >= telefones.size())
            return false;
        if (!validarTelefone(valor))
            return false;

        Telefone t = telefones.get(indiceTelefone);
        t.setRotulo(rotulo);
        t.setValor(valor);

        return true;
    }

    public String getNome() {
        return nome;
    }

    public String getSobrenome() {
        return sobrenome;
    }

    public LocalDate getDataNasc() {
        return dataNasc;
    }

    public String formata(String mascara, String valor) {
        MaskFormatter mask = null;
        String resultado = "";

        try {
            mask = new MaskFormatter(mascara);
            mask.setValueContainsLiteralCharacters(false);
            mask.setPlaceholderCharacter('_');
            resultado = mask.valueToString(valor);
        } catch (ParseException e) {
            e.printStackTrace();
        }

        return resultado;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");

        sb.append("Nome: ").append(nome).append(" ").append(sobrenome).append("\n");
        sb.append("Data de Nascimento: ").append(dataNasc.format(formatter)).append("\n");

        sb.append("Emails:\n");
        for (int i = 0; i < emails.size(); i++) {
            sb.append(" [").append(i).append("] ").append(emails.get(i).getRotulo()).append(": ")
                    .append(emails.get(i).getValor())
                    .append("\n");
        }

        sb.append("Telefones:\n");
        for (int i = 0; i < telefones.size(); i++) {
            sb.append(" [").append(i).append("] ").append(telefones.get(i).getRotulo()).append(": ")
                    .append(formata("(##) #####-####" , telefones.get(i).getValor()))
                    .append("\n");
        }

        return sb.toString();
    }
}