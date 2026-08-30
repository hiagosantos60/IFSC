package eng.telecom;

import eng.telecom.produtos.Dimensao;
import eng.telecom.produtos.SemFio;
import eng.telecom.produtos.Telefone;

public class App {
    public static void main(String[] args) {
        Dimensao d = new Dimensao(20, 20, 20);
        Dimensao d2 = new Dimensao(30, 30, 30);
        Telefone a = new Telefone(1, "1", "a1", 10, d);
        SemFio b = new SemFio(1, "2", "a2", 30, d2, 30, 5, 100);
        // podemos observar que a = b é true, mas b = a é false
        // para armazenar corretamente, tem que seguir a hierarquia do diagrama

        Telefone produtos[] = new Telefone[2];
        produtos[0] = a;
        produtos[1] = b;

        for (Telefone t : produtos) {
            if(t instanceof SemFio s) {
                double frequencia = s.getFrequencia();
                System.out.println(String.format("Semfio com frequencia %.2f: ", frequencia)); 
            }
        }

    }
}
