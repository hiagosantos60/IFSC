package engetelecom.poo.relogios;

import java.util.ArrayList;
import edu.princeton.cs.algs4.Draw;

public class RelogioDigitalDisplay extends RelogioDigital {

    private static final int TAM_PEQUENO = 1;
    private static final int TAM_MEDIO = 2;
    private static final int TAM_GRANDE = 3;

    private ArrayList<Display> displays = new ArrayList<>();
    private int tamanho;

    public RelogioDigitalDisplay(int x, int y, int tam) {
        this.posX = x;
        this.posY = y;
        
        if (tam == TAM_PEQUENO || tam == TAM_MEDIO || tam == TAM_GRANDE) {
            this.tamanho = tam;
        } else {
            this.tamanho = TAM_MEDIO; 
        }

        for (int i = 0; i < 6; i++) {
            displays.add(new Display());
        }
    }

    @Override
    public void desenhar(Draw canvas) {
        displays.get(0).setDigito(horas / 10);
        displays.get(1).setDigito(horas % 10);
        displays.get(2).setDigito(minutos / 10);
        displays.get(3).setDigito(minutos % 10);
        displays.get(4).setDigito(segundos / 10);
        displays.get(5).setDigito(segundos % 10);

        double fator = tamanho * 25; 
        
        double currentX = posX;

        for (int i = 0; i < 6; i++) {
            displays.get(i).desenhar(canvas, (int)currentX, posY, tamanho);

            currentX += 1.2 * fator;

            if (i == 1 || i == 3) {
                canvas.setPenColor(Draw.GREEN);

                double posicaoDosPontos = currentX + (0.15 * fator);
                double raioDoPonto = 0.1 * fator;

                canvas.filledCircle(posicaoDosPontos, posY + 0.6 * fator, raioDoPonto);
                canvas.filledCircle(posicaoDosPontos, posY + 1.4 * fator, raioDoPonto);

                currentX += 0.5 * fator;
            }
        }
    }
}