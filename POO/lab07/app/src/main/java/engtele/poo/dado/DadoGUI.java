package engtele.poo.dado;

import edu.princeton.cs.algs4.Draw;
import engtele.poo.ElementoGrafico;

public class DadoGUI extends Dado implements ElementoGrafico{
    private double x;
    private double y;

    public DadoGUI(int numeroDeFaces, double x, double y) {
        super(numeroDeFaces);
        this.x = x;
        this.y = y;
    }

    @Override
    public void desenhar(Draw d) {
        // implementar
    }

    @Override
    public void clicouDentro(double x, double y) {
        // implementar
    }
}
