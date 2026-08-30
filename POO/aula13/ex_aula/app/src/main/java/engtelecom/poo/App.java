package engtelecom.poo;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class App {
    private static boolean validarExpressao(String expressao) {
        Stack<Character> pilha = new Stack<>();
        List<Character> caracteresAbertura = new ArrayList<>();
        caracteresAbertura.add('{');
        caracteresAbertura.add('[');
        caracteresAbertura.add('(');

        int tamanho = expressao.length(); 
        // empilhando caracteres de abertura
        for (int i = 0; i < tamanho; i++) {
            char c = expressao.charAt(i);

            if(caracteresAbertura.contains(c)){
                pilha.add(c);
            }
            else if(c == '}' || c ==']' || c == ')'){
                if (pilha.isEmpty()) {
                    return false;
                }

                char topo = pilha.pop();

                if(!par(topo, c)){
                    return false;
                }
            }

        }

        return pilha.empty();

    }

    private static boolean par(char aberto, char fechado) {
        return (aberto == '(' && fechado == ')') ||
               (aberto == '[' && fechado == ']') ||
               (aberto == '{' && fechado == '}');
    }

    public static void main(String[] args) {
        String exp = "{[b x b - (4 x a x c)]/(2 x a)";
        
        if (validarExpressao(exp)) {
            System.out.println("A expressão é válida!");
        } else {
            System.out.println("A expressão não é válida!");
        }
    }
}
