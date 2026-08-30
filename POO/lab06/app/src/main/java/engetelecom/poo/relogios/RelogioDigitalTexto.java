package engetelecom.poo.relogios;

import edu.princeton.cs.algs4.Draw;
import java.awt.Font;

public class RelogioDigitalTexto extends RelogioDigital {

    private Font fontePersonalizada;

    public RelogioDigitalTexto(int x, int y, int tamanho) throws Exception {
        super();
        this.posX = x;
        this.posY = y;

        var arquivo = RelogioDigitalTexto.class.getClassLoader().getResourceAsStream("JetBrainsMono-Regular.ttf");
        
        Font fonteBase = Font.createFont(Font.TRUETYPE_FONT, arquivo);

        this.fontePersonalizada = fonteBase.deriveFont((float) tamanho);
    }

    @Override
    public void desenhar(Draw canvas) {
        canvas.setFont(this.fontePersonalizada);
        canvas.setPenColor(edu.princeton.cs.algs4.Draw.WHITE);

        String texto = String.format("%02d:%02d:%02d", this.horas, this.minutos, this.segundos);
        canvas.text(posX, posY, texto);
    }
}