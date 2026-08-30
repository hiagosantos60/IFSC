package lab02.ex03;

public class App {
    public static void main(String[] args) {
        
        if (args.length < 2) {
            IO.println("Entreda invalida... ");
        }

        String tipo = args[0];
        tipo = tipo.toLowerCase();

        int tam = Integer.parseInt(args[1]);      

        if (tam < 2) {
            IO.println("Entrada invalida! ");
            return;
        } 

        if (tipo.equals("triangulo")) {
            int c = 0;
            while (c <= tam) {
                IO.print("*".repeat(c));
                IO.println("");
                c++;
            }
        }

        if (tipo.equals("losango")) {
            if (tam % 2 == 0) {
                IO.println("Impossivel representar nesse tamanho... ");
                return;
            }

            int meio = tam / 2;
            int c = 0;

            while (c < tam) {
                int esp = Math.abs(meio - c);
                int ast = tam - (2 * esp);
        
                IO.println(" ".repeat(esp) + "*".repeat(ast));
        
                c++;
            }
        }

        if (tipo.equals("retangulo")) {
            if (args.length < 3) {
                IO.print("Entrada inválida para retangulo");
            }

            int alt = Integer.parseInt(args[2]); 

            int altura = alt;

            for (int i = alt; i >= 0; i--) {
                if (i == 0 || i == altura) {
                    IO.println("*".repeat(tam));
                } else {
                    IO.println("*" + " ".repeat(tam-2) + "*");
                }
            }
        }

    }
}
