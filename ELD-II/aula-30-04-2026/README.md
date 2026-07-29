# Decodificador BCD para Display de 7 Segmentos (VHDL)

Este projeto consiste em um circuito digital projetado em **VHDL** que atua como um decodificador de **BCD (Binary-Coded Decimal)** para um **display de 7 segmentos**. 

O propósito principal deste hardware é receber um valor binário de 4 bits (representando números de 0 a 9) e traduzi-lo para os sinais elétricos correspondentes que acendem os LEDs corretos de um display de 7 segmentos, permitindo a visualização direta do número.



O módulo `bcd2dsp` monitora continuamente a entrada combinacional de 4 bits. Quando uma combinação binária é detectada, a arquitetura processa o valor e ativa os segmentos necessários para formar o caractere numérico correspondente.

> ⚠️ **Nota de Implementação (Lógica Invertida):** Este projeto foi desenvolvido utilizando a lógica de **Anodo Comum (Ativo em Baixo)**. Isso significa que o bit **`0` acende** o segmento do display e o bit **`1` o mantém apagado**.

* **`sw`** (Input | `std_logic_vector(3 downto 0)`): Vetor de 4 bits que recebe o valor binário (comumente mapeado para chaves seletores/*switches* em uma placa FPGA).
* **`dsp`** (Output | `std_logic_vector(6 downto 0)`): Vetor de 7 bits enviado para o display. O mapeamento dos pinos segue a ordem padrão de segmentos: `(a, b, c, d, e, f, g)`.

## Tabela de Correspondência

Abaixo está a representação de como cada combinação binária na entrada (`sw`) altera o estado da saída (`dsp`) para formar os números:

| Entrada Binária (`sw`) | Valor Decimal | Saída Display (`dsp`) | Segmentos Acesos (Nível 0) |
| :---: | :---: | :---: | :---: |
| `0000` | 0 | `0000001` | a, b, c, d, e, f |
| `0001` | 1 | `1001111` | b, c |
| `0010` | 2 | `0010010` | a, b, d, e, g |
| `0011` | 3 | `0000110` | a, b, c, d, g |
| `0100` | 4 | `1001100` | b, c, f, g |
| `0101` | 5 | `0100100` | a, c, d, f, g |
| `0110` | 6 | `0100000` | a, c, d, e, f, g |
| `0111` | 7 | `0001111` | a, b, c |
| `1000` | 8 | `0000000` | Todos (a, b, c, d, e, f, g) |
| `1001` | 9 | `0001100` | a, b, c, d, f, g |
| *Outros (10 a 15)* | Inválido | `1111111` | Nenhum (Display Apagado) |

*Valores de entrada acima de 9 (`1001`) entram na cláusula `others` do circuito, apagando completamente o display.*
