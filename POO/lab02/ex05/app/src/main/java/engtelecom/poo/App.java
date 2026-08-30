package engtelecom.poo;

import java.util.Scanner;

public class App {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int[][] campo = new int[9][9];

        int t = 0;

        while(scan.hasNext()) {
            String linha = scan.nextLine();
            
            for (int i = 0; i < linha.length(); i++) { // fazendo a leitura e gravação em int 
                campo[t][i] = linha.charAt(i) == '.' ? 0 : 9; // "." == 0 && "*" == 9 que vamos guardar no campo 
            }
            t++;
        }

        for (int y = 0; y < campo.length; y++) {
            for (int x = 0; x < campo.length; x++) { 
                if (campo[x][y] == 9) { // se for asteristico 
                    // fazer validação da posição a ser analisada, nao pode estourar limite
                   for (int i = x - 1; i <= x + 1; i++) {
                        for (int j = y - 1; j <= y + 1; j++) {
                            
                            if (i >= 0 && i < 9 && j >= 0 && j < 9) { // garantir que estou dentro do array
    
                                if (campo[i][j] != 9) { // se for * não mexe
                                    campo[i][j]++;
                                }
                            }
                        }
                    }
                }
            }
        }

        System.out.println("Campo minado:");
        for (int y = 0; y < 9; y++) {
            for (int x = 0; x < 9; x++) {
                if (campo[y][x] == 9) {
                    System.out.print("*");
                } else {
                    System.out.print(campo[y][x]);
                }
            }
            System.out.println();
        }
        
        scan.close();
    }
}
