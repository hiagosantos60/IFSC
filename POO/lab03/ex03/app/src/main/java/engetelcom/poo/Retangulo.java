package engetelcom.poo;

import java.util.PrimitiveIterator;

public class Retangulo {
    private int largura;
    private int altura;
    private String codificacao;

    private static final int MIN_LAGURA = 4;
    private static final int MIN_ALTURA = 3;

    StringBuilder mensagem = new StringBuilder();

    // construtor padrão 
    public Retangulo() {
        this.largura = MIN_LAGURA;
        this.altura = MIN_ALTURA;
        this.codificacao = "ascii";
    }

    // construtor com parâmetros
    public Retangulo(int largura, int altura, String codificacao) {
        if((largura < MIN_LAGURA || altura < MIN_ALTURA) && (!codificacao.equals("ascii") || !codificacao.equals("uft8"))){
            this.largura = MIN_LAGURA;
            this.altura = MIN_ALTURA;
            this.codificacao = "ascii";
        } else{
            this.largura = largura;
            this.altura = altura;
            this.codificacao = codificacao;
        }
    }

    public void setLargura(int largura) {
        if(largura > MIN_LAGURA) {
            this.largura = largura;
        } else {
            this.largura = MIN_LAGURA;
        }
    }
    public void setAltura(int altura) {
        if(altura > MIN_ALTURA){
            this.altura = altura;
        } else {
            this.altura = MIN_ALTURA;
        }
    }
    public void setCodificacao(String codificacao) {
        if (!codificacao.equals("ascii") || !codificacao.equals("uft8")){
            this.codificacao = "ascii";
        } else {
            this.codificacao = codificacao;
        }
    }

    public int getLargura() {
        return largura;
    }
    public int getAltura() {
        return altura;
    }
    public String getCodificacao() {
        return codificacao;
    }

    public double getArea() {
        return largura*altura;
    }
    public double getPerimetro() {
        return 2*(largura+altura);
    }

    @Override
    public String toString() {
        String eS = (codificacao.equals("ascii")) ? "+" : "\u250c";
        String dS = (codificacao.equals("ascii")) ? "+" : "\u2510";
        String eI = (codificacao.equals("ascii")) ? "+" : "\u2514";
        String dI = (codificacao.equals("ascii")) ? "+" : "\u2518";
        String linha = (codificacao.equals("ascii")) ? "-" : "\u2500";
        String coluna = (codificacao.equals("ascii")) ? "|" : "\u2502";   

        String cima = eS + linha.repeat(largura-2) + dS + "\n";

        String miolo = coluna + " ".repeat(largura-2) + coluna + "\n";

        String baixo = eI + linha.repeat(largura-2) + dI;

        return cima + miolo.repeat(altura-2) + baixo;
    }

}
