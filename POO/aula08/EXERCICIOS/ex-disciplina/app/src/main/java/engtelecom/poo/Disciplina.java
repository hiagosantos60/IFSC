package engtelecom.poo;

public class Disciplina {
    private String disciplina;
    private int creditos;
    private String professor;
    private int qtdAlunos;

    public void setCreditos(int a) {
        creditos = a;
    }
    public int getCreditos() {
        return creditos;
    }

    public void setDisciplina(String s) {
        disciplina = s;
    }
    public String getDisciplina() {
        return disciplina;
    }

    public void setProfessor(String p) {
        professor = p;   
    }
    public String getProfessor() {
        return professor;
    }

    public void setAlunos(int a) {
        qtdAlunos = a;
    }
    public int getAlunos() {
        return qtdAlunos;
    }
}
