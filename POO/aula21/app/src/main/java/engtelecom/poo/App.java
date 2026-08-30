package engtelecom.poo;

import java.util.ArrayDeque;
import java.util.Deque;

import engtelecom.poo.ex01.Planetas;
import engtelecom.poo.ex02.Carta;
import engtelecom.poo.ex02.Naipes;
import engtelecom.poo.ex02.Valor;

public class App {
    public static void main(String[] args) {
        // String sigla = IO.readln("Qual a sigla: ");
        // int dia1 = Integer.parseInt(IO.readln("Primeiro dia: "));
        // DiasDaSemana d1 = DiasDaSemana.getByCodigo(dia1);
        // int dia2 = Integer.parseInt(IO.readln("Segundo dia: "));
        // DiasDaSemana d2 = DiasDaSemana.getByCodigo(dia2);

        // DiasDaSemana[] dias = {d1,d2};

        // Disciplina d = new Disciplina(sigla, dias);

        // IO.print(d);

        // listando todos os planetas
        // for (Planetas p : Planetas.values()) {
        //     IO.println(p);
        // }

        Deque<Carta> baralho = new ArrayDeque<>();

        for (Naipes n : Naipes.values()) {
            for (Valor v : Valor.values()) {
                Carta carta = new Carta(n, v);

                baralho.add(carta);
            }
        }

        for (Carta c : baralho){
            System.out.println(c);
        }
    }
}
