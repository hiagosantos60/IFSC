
package engtelecom.poo;

import java.text.ParseException;
import java.util.InputMismatchException;
import java.util.Scanner;

import javax.swing.text.MaskFormatter;

public class App {
    static String formatar(String mascara, String valor) throws ParseException{
        MaskFormatter maskFormatter = null;

        maskFormatter = new MaskFormatter(mascara);
        
        return "";
    }

    static void exceptions() {
        Scanner ler = new Scanner(System.in);
        int a,b;

        try{
            System.out.println("Entre com um numero: ");
            a = ler.nextInt();
            System.out.println("Entre com outro numero: ");
            b = ler.nextInt();

            int res = a/b;

            System.out.println(a + " dividido por " + b + " = " + res);
        } catch(InputMismatchException e) {
            System.err.println("Só permitimos numeros inteiros");
            System.out.println(e);
            ler.nextLine();
        } catch(ArithmeticException e){
            System.err.println("Não dividirás por zero!!");
            System.out.println(e);
            ler.nextLine();
        } catch (Exception e) {
            System.err.println("lascou");
        }

        System.out.println("acabou");
        ler.close();
    }

    public static void main(String[] args) {
        String s = formatar("(##)", "48");
    }
}
