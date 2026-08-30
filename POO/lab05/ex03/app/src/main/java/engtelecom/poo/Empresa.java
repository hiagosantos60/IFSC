package engtelecom.poo;

import java.util.ArrayList;
import java.util.HashMap;

public class Empresa {
    private HashMap<String, Veiculo> veiculos = new HashMap<>();
    private HashMap<Integer, Motorista> motoristas = new HashMap<>();
    private ArrayList<Registro> registros = new ArrayList<>();
    private int cnpj;

    public Empresa(int cnpj) {
        this.cnpj = cnpj;
    }

    public boolean addMotorista(Motorista motorista) {
        int cpf = motorista.getCpf();

        if(motoristas.containsKey(cpf)) return false;

        motoristas.put(cpf, motorista);
        return true;
    }

    public boolean addVeiculo(Veiculo veiculo){
        String placa = veiculo.getPlaca();

        if(veiculos.containsKey(placa)) return false;

        veiculos.put(placa, veiculo);
        return true;
    }

    public boolean addRegistro(Registro registro){
        return registros.add(registro);
    }

    public int getCnpj() {
        return cnpj;
    }
}
