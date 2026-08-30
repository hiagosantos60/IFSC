package engtelecom.poo.ex01;

public enum Planetas {
    // crie um enum para represetar planetas e sua posição em relação ao sol
    // Mercúrio, Vênus, Terra, Marte, Júpiter, Saturno, Urano e Netuno

    MERCURIO("Mercúrio",1),
    VENUS("Vênus", 2),
    TERRA("Terra",3),
    MARTE("Marte",4),
    JUPITER("Júpiter",5),
    SATURNO("Saturno",6),
    URANO("Urano",7),
    NETURNO("Neturno",8);

    public final int posicao;
    public final String nome;

    private Planetas( String nome, int posicao) {
        this.posicao = posicao;
        this.nome = nome;
    }

    public static Planetas getByPosicao(int p) {
        for (Planetas c : Planetas.values()) {
            if(c.posicao == p) {
                return c;
            }
        }
        throw new IllegalArgumentException("Código inválido");
    }

    @Override
    public String toString() {
        return String.format("%s = %d" , nome, posicao);
    }
}
