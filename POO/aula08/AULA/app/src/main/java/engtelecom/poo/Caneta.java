package engtelecom.poo;

public class Caneta {
    // Atribuitos
    private String cor;
    private double nivelTinta;
    private boolean tampada;

    public void setColor(String c) {
        cor = c;
    }
    public String getColor() {
        return cor;
    }

    public void setNivel() {
        nivelTinta = 100;
    }
    public double getNivel() {
        return nivelTinta;
    }

    public void setTampada() {
        tampada = !tampada;
    }
    public boolean getTampada() {
        return tampada;
    }

    public String draw(double x1, double x2, double y1, double y2){
        if (tampada == false) return "A caneta está tampada, abra a caneta.";

        double distancia = Math.sqrt(Math.pow(x2-x1, 2)+Math.pow(y2-y1, 2));
        double gasto = (distancia*0.01);

        if (gasto > nivelTinta) return "Sem tinta suficiente";

        nivelTinta = nivelTinta - gasto;

        return String.format("Desenhei! Percorri %.2f cm e gastei %.2f de tinta", distancia, (distancia*0.01));
    }

}