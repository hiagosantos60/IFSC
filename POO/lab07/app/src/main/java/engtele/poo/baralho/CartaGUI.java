package engtele.poo.baralho;
import java.util.Random;

import edu.princeton.cs.algs4.Draw;
import engtele.poo.ElementoGrafico;

public class CartaGUI extends Carta implements ElementoGrafico {
    private double cX;
    private double cY;
    private boolean virada = true;
    private String nomeCarta;

    public CartaGUI(Naipes naipe, Valor valor, double cX, double cY) {
        super(naipe, valor);
        this.cX = cX;
        this.cY = cY;
        this.nomeCarta = "cartas/cartas/" + valor.getInicial() + naipe.getInicial() + ".png";
    }

    @Override
    public void desenhar (Draw draw) {
        if(virada) {
            draw.picture(cX,cY,nomeCarta);   
        } else {
            Random r = new Random();
            if (r.nextBoolean()) {
                draw.picture(cX,cY,"cartas/cartas/fundoa.png");   
            } else {
                draw.picture(cX,cY,"cartas/cartas/fundov.png");
            }
        }
        draw.show();
    }

    public void virarCarta() {
        virada = !virada;
    }

    public boolean clicouDentro(double x, double y) {
        int largura = 72;  
        int altura = 96;

        if (x > this.cX - largura/2 && x < this.cX + largura/2) {
            if (y > this.cY - altura/2 && y < this.cY + altura/2) {
                return true;
            }
        }

        return false;
    }

}
