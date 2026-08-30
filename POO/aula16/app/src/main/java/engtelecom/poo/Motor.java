package engtelecom.poo;

public class Motor {
    private String tipoMotor;
    private boolean ligado;
    private double consumo;

    public Motor(String tipoMotor, double consumo) {
        if (!tipoMotor.equals("turbina") || !tipoMotor.equals("helice")) {
            this.tipoMotor = "helice";
            this.consumo = consumo;
        } else {
            this.tipoMotor = tipoMotor;
            this.consumo = consumo;
        }
    }

    public boolean isLigado() {
        return ligado;
    }

    public void ligaDesliga() {
        ligado = !ligado;
    }

    @Override
    public String toString() {
        String s = String.format("""
            
                Tipo: %s
                Consumo: %.2f
                """, tipoMotor, consumo); 

        return s;
    }
    
}
