package engtele.poo.dado;

import java.util.Random;

public class Dado {
    private int valorFace;
    private int numeroDeFaces;
    protected int[] estatisticas;
    private Random r;

    public Dado(int numeroDeFaces) {
        this.valorFace = 1;
        this.numeroDeFaces = numeroDeFaces;
        this.estatisticas = new int[numeroDeFaces];
        this.r = new Random();
    }

    // final para não deixar o método ser sobreescrito 
    public final int jogar(){
        valorFace = r.nextInt(1,7);
        this.estatisticas[this.valorFace-1]++;
        return valorFace;
    }

    public String gerarEstatisticas() {
        StringBuilder sb = new StringBuilder();
        sb.append("estatisticas completas:");
        for (int i = 0; i < estatisticas.length; i++) {
            sb.append(String.format("Face %d: %d vezes", i+1, estatisticas[i]));
        }
        return sb.toString();
    }
}
