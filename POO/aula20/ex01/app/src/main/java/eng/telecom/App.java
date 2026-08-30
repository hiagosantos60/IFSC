package eng.telecom;

import java.util.ArrayList;

import eng.telecom.personagens.Aldeao;
import eng.telecom.personagens.Arqueiro;
import eng.telecom.personagens.Cavaleiro;
import eng.telecom.personagens.Personagem;

public class App {
    public static void main(String[] args) {
        ArrayList<Personagem> persongens = new ArrayList<>();

        Aldeao marcos = new Aldeao("Marcos");
        Arqueiro wagner = new Arqueiro("Wagner");
        Cavaleiro mateus = new Cavaleiro("Mateus");

        persongens.add(marcos);
        persongens.add(wagner);
        persongens.add(mateus);

        for (Personagem p : persongens) {
            if(p instanceof Aldeao a) {
                System.out.println(a.andar());
            }
        }
    }
}
