package engtelecom.poo;

/**
 * Essa é uma documentação de classe e o asteristico indica linha de javadoc
 * Calculadora que realiza as 4 operações aritiméticas
 * @author Hiago Ritter Santos
 */
public class Calculadora {
    
    /**
     * Aqui estamos documentando um método da classe
     * Realiza a soma de dois inteiros e retorna o resultado
     * @param a primeiro operando
     * @param b segundo operando
     * @return resultado da operação
     */
    public int soma(int a, int b) {
        return a+b;
    }

    /**
     * Função que verifica tipo de triângulo 
     * @param a primeiro lado
     * @param b segundo lado
     * @param c terceiro lado 
     * @return retorna o tipo de triagulo 
     */
    public String tipoTriangulo(int a, int b, int c){
        if(a == 0 || b == 0 || c == 0) return "invalido";
        if (a < 0 || b < 0 || c < 0) return "invalido";

        if(a+b>c && b+c>a && a+c>b) {
            if(a == b && a == c && b == c){
                return "equilatero";
            } else if(a != b && a != c && b != c){
                return "escaleno";
            } else if(a == b || b == c || a == c) {
                return "isosceles";
            } else {
                return "invalido";
            } 
        } else {
                return "invalido";
        }
    }
}
