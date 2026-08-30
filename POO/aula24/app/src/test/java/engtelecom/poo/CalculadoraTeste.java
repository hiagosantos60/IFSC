package engtelecom.poo;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

public class CalculadoraTeste {
    @Test
    public void soma() {
        Calculadora c = new Calculadora();
        assertEquals(12, c.soma(1,11), "positivos");
    }

    @Test
    public void triagulo(){
        Calculadora c = new Calculadora();

        assertEquals("equilatero", c.tipoTriangulo(1, 1, 1), "Deveria ser equilatero");
        assertEquals("escaleno", c.tipoTriangulo(5, 7, 8), "Deveria ser escaleno");
        assertEquals("isosceles", c.tipoTriangulo(5, 5, 6), "Deveria ser isosceles");
        assertEquals("invalido", c.tipoTriangulo(-5, 5, 6), "Não pode número negativo");
        assertEquals("invalido", c.tipoTriangulo(0, 2, 1), "Não pode ser zero");
        assertEquals("invalido", c.tipoTriangulo(0, 0, 0), "Não é um triângulo");
        assertEquals("invalido", c.tipoTriangulo(10, 1, 1), "Não é um triângulo");
        assertEquals("invalido", c.tipoTriangulo(-1, -1, -1), "Não é triângulo");
        assertEquals("invalido", c.tipoTriangulo(-1, 2, 3), "Não é triângulo");
        assertEquals("invalido", c.tipoTriangulo(-1, -1, -1), "Não é triângulo");
        assertEquals("invalido", c.tipoTriangulo(-1, 2, 3), "Não é triângulo");
        assertEquals("isosceles", c.tipoTriangulo(6, 5, 5), "Não é triângulo");
        assertEquals("isosceles", c.tipoTriangulo(5, 6, 5), "Não é triângulo");
        assertEquals("isosceles", c.tipoTriangulo(5, 5, 6),  "Não é triângulo");
    }
}
