package lab02.ex04;

import java.util.Random;

public class App {
    public static void main(String[] args) {
        Random r = new Random(); 

        String[][] matriz = new String[9][9]; 

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                matriz[i][j] = "."; 
            }
        }

        int c = 0;
        while (c < 10) {
            int x = r.nextInt(9); 
            int y = r.nextInt(9);
            if (matriz[x][y].equals(".")) {
                matriz[x][y] = "*";
                c++;
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char caracter = matriz[i][j].charAt(0); 
                IO.print(caracter);
            }
            IO.println("");
        }
    }
}
