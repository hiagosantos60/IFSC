package engtelecom.poo;

public class Contador {
    int valorAtual;

    //Atribuir um valor
    public void setValor(int v) {
        if (v < 0) valorAtual = 0;
        valorAtual = v; 
    }

    //Obter o valor armazenado 
    public int getValor() {
        return valorAtual;
    }

    public void incrementar(){
        valorAtual += 1;
    }
}