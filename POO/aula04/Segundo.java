void main() {

    // int i = 10;
    // String resultado = "iniciando";

    // switch (i) {
    //     case 1:
    //         IO.println("1");
    //         break;
    //     case 2:
    //         IO.println("2");
    //         break;
    //     case 3:
    //         IO.println("3");
    //         besultado = "Outro valor...";
    // }


    // String resultado_dois = switch(i) {
    //     case 1 -> "Um";
    //     case 2 -> "Dois";
    //     case 3 -> "Três";
    //     default -> "Outro valor";
    // }

    // IO.println(resultado);

    // String resultado_dois = switch(i) {
    //     case 1 -> "Um";
    //     case 2 -> "Dois";
    //     case 3 -> "Três";
    //     default -> "Outro valor";
    // }

    // IO.println(resultado);

    // exercicio em sala
    int valor = 1;

    int[][] matriz = new int [3][3];
    for(int i=0; i<3; i++) {
        for (int j=0; j<3; j++){
            matriz[i][j] = valor;

            if (i == j) {
                int k = i;
                while (k > 0) {
                    IO.print("-");
                    k--;
                }
                IO.print(matriz[i][j]);
                IO.print("\n");
            }

            valor++;
        }
    }
}