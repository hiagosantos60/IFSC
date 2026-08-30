package engetelecom.poo.relogios;

import java.awt.Color;
import edu.princeton.cs.algs4.Draw;

public class Display {
    private boolean[] segmentos = new boolean[7]; 

    public void setDigito(int num) {
        switch (num) {
            case 0:
                // acende tudo, exceto o segmento do meio (G)
                segmentos = new boolean[]{true, true, true, true, true, true, false};
                break;
            case 1:
                // acende apenas as duas barras da direita (B e C)
                segmentos = new boolean[]{false, true, true, false, false, false, false};
                break;
            case 2:
                // acende A, B, G, E, D
                segmentos = new boolean[]{true, true, false, true, true, false, true};
                break;
            case 3:
                // acende A, B, C, D, G
                segmentos = new boolean[]{true, true, true, true, false, false, true};
                break;
            case 4:
                // acende F, G, B, C
                segmentos = new boolean[]{false, true, true, false, false, true, true};
                break;
            case 5:
                // acende A, F, G, C, D
                segmentos = new boolean[]{true, false, true, true, false, true, true};
                break;
            case 6:
                // acende A, F, E, D, C, G
                segmentos = new boolean[]{true, false, true, true, true, true, true};
                break;
            case 7:
                // acende A, B, C
                segmentos = new boolean[]{true, true, true, false, false, false, false};
                break;
            case 8:
                // acende todos os segmentos
                segmentos = new boolean[]{true, true, true, true, true, true, true};
                break;
            case 9:
                // acende A, B, C, D, F, G 
                segmentos = new boolean[]{true, true, true, true, false, true, true};
                break;
            default:
                // Se for um valor inválido, apaga todos os segmentos
                segmentos = new boolean[]{false, false, false, false, false, false, false};
                break;
        }
    }

    public void desenhar(Draw canvas, int x, int y, int tamanho) {
        double fator = tamanho * 25; 
        
        Color corAcesa = Draw.GREEN; 
        
        Color corApagada = new Color((int)(corAcesa.getRed()*0.15), (int)(corAcesa.getGreen()*0.15), (int)(corAcesa.getBlue()*0.15));

 
        double yA = y + 1.8 * fator;
        double[] xA = {0.1*fator+x, 0.2*fator+x, 0.8*fator+x, 0.9*fator+x, 0.8*fator+x, 0.2*fator+x};
        double[] yA_pontos = {0.2*fator+yA, 0.3*fator+yA, 0.3*fator+yA, 0.2*fator+yA, 0.1*fator+yA, 0.1*fator+yA};

        double yB = y + 0.9 * fator;
        double[] xB = {0.9*fator+x, 1.0*fator+x, 1.0*fator+x, 0.9*fator+x, 0.8*fator+x, 0.8*fator+x};
        double[] yB_pontos = {0.2*fator+yB, 0.3*fator+yB, 1.0*fator+yB, 1.1*fator+yB, 1.0*fator+yB, 0.3*fator+yB};

        double yC = y + 0.0 * fator;
        double[] xC = {0.9*fator+x, 1.0*fator+x, 1.0*fator+x, 0.9*fator+x, 0.8*fator+x, 0.8*fator+x};
        double[] yC_pontos = {0.2*fator+yC, 0.3*fator+yC, 1.0*fator+yC, 1.1*fator+yC, 1.0*fator+yC, 0.3*fator+yC};

        double yD = y + 0.0 * fator;
        double[] xD = {0.1*fator+x, 0.2*fator+x, 0.8*fator+x, 0.9*fator+x, 0.8*fator+x, 0.2*fator+x};
        double[] yD_pontos = {0.2*fator+yD, 0.3*fator+yD, 0.3*fator+yD, 0.2*fator+yD, 0.1*fator+yD, 0.1*fator+yD};

        double yE = y + 0.0 * fator;
        double[] xE = {0.1*fator+x, 0.2*fator+x, 0.2*fator+x, 0.1*fator+x, 0.0*fator+x, 0.0*fator+x};
        double[] yE_pontos = {0.2*fator+yE, 0.3*fator+yE, 1.0*fator+yE, 1.1*fator+yE, 1.0*fator+yE, 0.3*fator+yE};

        double yF = y + 0.9 * fator;
        double[] xF = {0.1*fator+x, 0.2*fator+x, 0.2*fator+x, 0.1*fator+x, 0.0*fator+x, 0.0*fator+x};
        double[] yF_pontos = {0.2*fator+yF, 0.3*fator+yF, 1.0*fator+yF, 1.1*fator+yF, 1.0*fator+yF, 0.3*fator+yF};

    
        double yG = y + 0.9 * fator;
        double[] xG = {0.1*fator+x, 0.2*fator+x, 0.8*fator+x, 0.9*fator+x, 0.8*fator+x, 0.2*fator+x};
        double[] yG_pontos = {0.2*fator+yG, 0.3*fator+yG, 0.3*fator+yG, 0.2*fator+yG, 0.1*fator+yG, 0.1*fator+yG};

        double[][] todosX = { xA, xB, xC, xD, xE, xF, xG };
        double[][] todosY = { yA_pontos, yB_pontos, yC_pontos, yD_pontos, yE_pontos, yF_pontos, yG_pontos };

        for (int i = 0; i < 7; i++) {
            canvas.setPenColor(segmentos[i] ? corAcesa : corApagada);

            canvas.filledPolygon(todosX[i], todosY[i]);
        }
    }
}