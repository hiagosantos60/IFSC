package engtelecom.poo;

public class Caixa<T> {
    private T conteudo;

    public Caixa(T conteudo) {
        this.conteudo = conteudo;
    }

    public void set(T obj){
        this.conteudo = obj;
    }

    public T getConteudo() {
        return this.conteudo;
    }
}
