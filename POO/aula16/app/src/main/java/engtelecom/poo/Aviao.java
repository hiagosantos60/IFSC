package engtelecom.poo;

import java.util.ArrayList;

public class Aviao {
    private int maxPassageiros;
    private int maxTripulantes;
    private double capacidadeCombustivel;
    private int qtdMotores;
    ArrayList<Motor> motores;

    public Aviao(int maxPassageiros, int maxTripulantes, double capacidadeCombustivel, int qtdMotores, String tipoMotor, double consumoMotor) {
        this.maxPassageiros = maxPassageiros;
        this.maxTripulantes = maxTripulantes;
        this.capacidadeCombustivel = capacidadeCombustivel;

        this.qtdMotores = (qtdMotores > 0 && qtdMotores <= 8) ? qtdMotores : 1;
        
        this.motores = new ArrayList<Motor>();

        for (int i = 0; i < this.qtdMotores ; i++) {
            motores.add(new Motor(tipoMotor, consumoMotor));
        }   
    }

    public void ligarTodosMotores() {
        // implementar
    }

    public void desligarTodosMotores() {
        // implementar
    }

    public void ligarMotorEspecifico() {
        // implementar
    }

    public void desligarMotorEspecifico () {
        //
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Maxímo de passageiros: ");
        sb.append(maxPassageiros);
        sb.append("\n");
        sb.append("Máximo de tripulantes: ");
        sb.append(maxTripulantes);
        sb.append("\n");
        sb.append("Máximo de combustível: ");
        sb.append(capacidadeCombustivel);
        sb.append("\n");
        sb.append("Quantidade de motores: ");
        sb.append(qtdMotores);
        sb.append("\n");

        // para cada motor adicionamos no sb
        sb.append("=== Motores ===");
        sb.append(motores.get(0));

        return sb.toString();
    }
}

