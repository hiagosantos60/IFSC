void main () {
    // Leia 4 notas das avaliações - numero real de 0 a 10
    // Calcule e apresente a medias > numero inteiro de 0 a 10

    double[] notas = new double[4];

    for (int i = 0; i<notas.length; i++) {
        notas[i] = Double.parseDouble(IO.readln("Qual valor da nota " + (i+1) + "a :")); 
    }

    double media = 0;
    
    for (double n : notas) {
        media = media + n;
    }

    media = Math.round((float)(media/4));
    
    IO.println("Sua média é " + media);
}