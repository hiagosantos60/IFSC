package engetelecom.poo;

import java.util.ArrayList;
import edu.princeton.cs.algs4.Draw;
import engetelecom.poo.relogios.*;

public class App {
    public static void main(String[] args) throws Exception {
        Draw canvas = new Draw();
        canvas.setXscale(0, 800);
        canvas.setYscale(0, 600);
        canvas.setCanvasSize(800,600);
        canvas.enableDoubleBuffering();

        ArrayList<Relogio> listaDeRelogios = new ArrayList<>();
        listaDeRelogios.add(new RelogioAnalogico(400, 350, 150));
        listaDeRelogios.add(new RelogioDigitalDisplay(50, 100, 1));
        listaDeRelogios.add(new RelogioDigitalTexto(600, 560, 30));

        new Thread(() -> {
            IO.println("======CONTROLE DOS RELÓGIOS======");
            while (true) {
                String tecla = IO.readln("Digite [1] Relógio, [2] Progressivo, [3] Regressivo: ");
                
                if (tecla.equals("1")) {
                    for (Relogio r : listaDeRelogios) {
                        if (r instanceof RelogioDigital) ((RelogioDigital) r).setModoRelogio();
                    }
                } else if (tecla.equals("2") || tecla.equals("3")) {
                    int modo = Integer.parseInt(tecla);
                    int h = Integer.parseInt(IO.readln("Horas: ").trim());
                    int m = Integer.parseInt(IO.readln("Minutos: ").trim());
                    int s = Integer.parseInt(IO.readln("Segundos: ").trim());
                    
                    for (Relogio r : listaDeRelogios) {
                        if (r instanceof RelogioDigital) ((RelogioDigital) r).setModoRelogio(h, m, s, modo);
                    }
                }
            }
        }).start();

        while (true) {
            canvas.clear(Draw.BLACK);
            for (Relogio r : listaDeRelogios) {
                r.avancarTempo();
                r.desenhar(canvas);
            }
            canvas.show();
            canvas.pause(1000);
        }
    }
}