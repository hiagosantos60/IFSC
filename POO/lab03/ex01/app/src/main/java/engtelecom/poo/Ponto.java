package engtelecom.poo;

public class Ponto {
    private double x;
    private double y;

    public double calcularDistancia(Ponto b){
        double dist = Math.sqrt((Math.pow((b.getX() - this.x),2)) + (Math.pow(b.getY() - this.y, 2)));
        return dist;
    }

    public Ponto(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public void setX(double x) {
        this.x = x;
    }
    public void setY(double y) {
        this.y = y;
    }
    public double getX() {
        return x;
    }
    public double getY() {
        return y;
    }

    @Override
    public String toString() {
        return String.format("{%.2f;%.2f}", x, y);
    }
}
