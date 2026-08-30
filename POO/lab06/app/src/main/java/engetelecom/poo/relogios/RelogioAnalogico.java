package engetelecom.poo.relogios;

import edu.princeton.cs.algs4.Draw;

public class RelogioAnalogico extends Relogio {

    private double raio; 

    public RelogioAnalogico(int x, int y, double raio) {
        this.posX = x;
        this.posY = y;
        this.raio = raio;
        this.setHorario(); 
    }

    @Override
    public void desenhar(Draw canvas) {
        canvas.setPenColor(Draw.WHITE);
        canvas.filledCircle(posX, posY, raio);

        canvas.setPenColor(Draw.BLACK);
        canvas.setPenRadius(0.015);
        for (int i = 0; i < 12; i++) {
            double angulo = i * (Math.PI / 6);
            
            double xExterna = posX + raio * 0.95 * Math.sin(angulo);
            double yExterna = posY + raio * 0.95 * Math.cos(angulo);
            double xInterna = posX + raio * 0.80 * Math.sin(angulo);
            double yInterna = posY + raio * 0.80 * Math.cos(angulo);
            
            canvas.line(xInterna, yInterna, xExterna, yExterna);
        }

        double anguloSegundos = (this.segundos * Math.PI / 30);
        double anguloMinutos = (this.minutos * Math.PI / 30) + (this.segundos * Math.PI / 1800);
        double anguloHoras = ((this.horas % 12) * Math.PI / 6) + (this.minutos * Math.PI / 360);

        double hx = posX + (raio * 0.5) * Math.sin(anguloHoras);
        double hy = posY + (raio * 0.5) * Math.cos(anguloHoras);
        canvas.line(posX, posY, hx, hy);

        canvas.setPenRadius(0.01);
        double mx = posX + (raio * 0.75) * Math.sin(anguloMinutos);
        double my = posY + (raio * 0.75) * Math.cos(anguloMinutos);
        canvas.line(posX, posY, mx, my);

        canvas.setPenColor(Draw.RED);
        canvas.setPenRadius(0.005);
        double sx = posX + (raio * 0.85) * Math.sin(anguloSegundos);
        double sy = posY + (raio * 0.85) * Math.cos(anguloSegundos);
        canvas.line(posX, posY, sx, sy);

        canvas.setPenRadius(); 
        canvas.setPenColor(Draw.BLACK); 
    }
}