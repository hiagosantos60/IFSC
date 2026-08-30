
package org.example;

import java.util.Random;

public class App {

    public static void main(String[] args) {
        Random num = new Random();
        int i = num.nextInt(100) + 1; // número aleatório de 1 a 100

        int chute = 0;

        while (chute != i) {
            chute = Integer.parseInt(IO.readln("Entre com seu chute: "));

            if (i == chute) {
              IO.println("Acertou!");
            } else if (i > chute) {
                IO.println("Maior...");
            } else {
                IO.println("Menor...");
            }  
        }   
    }
}
