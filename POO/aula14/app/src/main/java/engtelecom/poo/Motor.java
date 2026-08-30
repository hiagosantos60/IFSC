package engtelecom.poo;

public class Motor {
    private int hp;
    private int giroAtual;
    private int cilindros;
    
    public Motor(int hp, int cilindros) {
        this.hp = hp;
        this.cilindros = cilindros;
        this.giroAtual = 0;
    }

    public void acelerar(int g) {
        this.giroAtual = g;
    }

    public int getHp() {
        return hp;
    }

    public int getGiroAtual() {
        return giroAtual;
    }

    public int getCilindros() {
        return cilindros;
    }
    
    
}
