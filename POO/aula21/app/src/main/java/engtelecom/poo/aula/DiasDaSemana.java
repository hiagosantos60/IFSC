package engtelecom.poo.aula;

public enum DiasDaSemana {
    DOMINGO(1,"Domingo"),
    SEGUNDA(2,"Segunda Feira"),
    TERCA(3, "Terça Feira"),
    QUARTA(4, "Quarta Feira"),
    QUINTA(5, "Quinta Feira"),
    SEXTA(6, "Sexta Feira"),
    SABADO(7, "Sábado");

    public final int codigo;
    public final String extenso;

    private DiasDaSemana(int codigo, String extenso) {
        this.codigo = codigo;
        this.extenso = extenso;
    }

    public static DiasDaSemana getByCodigo(int c) {
        for (DiasDaSemana dia : DiasDaSemana.values()) {
            if(dia.codigo == c) {
                return dia;
            }
        }

        throw new IllegalArgumentException("Código inválido");
    }

    @Override
    public String toString() {
        return extenso;
    }
}
