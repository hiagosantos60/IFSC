package poo.engetelecom;

import java.awt.Color;
import java.util.concurrent.TimeUnit;

import edu.princeton.cs.algs4.Draw;

public class App {
    /**
     * @param args
     * @throws InterruptedException 
     */
    public static void main(String[] args) throws InterruptedException {

        Draw draw = new Draw();
        draw.setXscale(0,800);
        draw.setYscale(0,800);
        
        draw.enableDoubleBuffering();

        draw.setCanvasSize(800,800);
        draw.setPenColor(Color.red);

        draw.filledCircle(400,400,100);

        draw.point(400, 400);

        draw.square(100, 700, 40);

        double[] x = {100,300,500,600};
        double[] y = {100,300,300,100};

        draw.polygon(x, y);

        draw.text(400, 400, "POO");

        draw.setFontSize(30);

        for (int i = 0; i < 10; i++) {
            draw.clear();
            draw.text(400, 400, ""+i);

            draw.show();

            TimeUnit.SECONDS.sleep(1);
        
        }

        draw.setPenColor(Color.gray);
        draw.clear();
        for (int i = 0; i < 800; i+=50) {
            draw.line(i, 0, i, 800);
            draw.line(0, i, 800, i);
        }
        draw.show();
        
    }
}
