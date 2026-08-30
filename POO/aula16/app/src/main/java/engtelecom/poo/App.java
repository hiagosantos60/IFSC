package engtelecom.poo;

public class App {
    public static void main(String[] args) {
        Aviao a = new Aviao(10, 12, 100, 4, "helice", 10);
        Aviao b = new Aviao(20, 25, 200, 200, "aaa", 19);
        Aviao c = new Aviao(40, 45, 80, (-3), "ffff", 45);

        System.out.println("Avião A:");
        System.out.println(a);
        System.out.println("Avião B");
        System.out.println(b);
        System.out.println("Avião C");
        System.out.println(c);
    }
}
