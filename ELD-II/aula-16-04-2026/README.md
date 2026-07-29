# Multiplexador 4x1 em VHDL: Estudo de Modelagem Combinacional

Este projeto, tem como propósito demonstrar as diferentes formas de descrever um **Multiplexador 4 para 1 (MUX 4x1)** utilizando a linguagem VHDL.



## Propósito do Circuito (MUX 4x1)

Um multiplexador é um seletor de dados. Ele possui várias entradas de dados e uma única saída. A escolha de qual entrada será conectada à saída é feita pelos pinos de seleção (`Sel`). 

Neste projeto, temos:
*   **`X`** (Entrada): Um vetor de 4 bits representando os canais de dados de entrada (`X(0)`, `X(1)`, `X(2)`, `X(3)`).
*   **`Sel`** (Seleção): Um vetor de 2 bits (`Sel(1)` e `Sel(0)`) que controla o roteamento.
*   **`Y`** (Saída): Um único bit de saída que reflete o valor do canal escolhido.

---

## Análise das Arquiteturas Implementadas

O projeto implementa a entidade `multiplexadores` utilizando três abordagens concorrentes distintas. Todas geram exatamente o mesmo circuito final no hardware, mas possuem sintaxes e usos diferentes:

### 1. Arquitetura: `v_logica_pura` (Portas Lógicas)
Descreve o MUX em seu nível mais baixo, utilizando Álgebra de Boole (Soma de Produtos). 
O código mapeia diretamente as portas lógicas **AND**, **OR** e **NOT**. É a tradução direta do circuito elétrico clássico de um MUX, avaliando mintermos.

### 2. Arquitetura: `v_WHEN_ELSE` (Atribuição Condicional)
Utiliza a instrução concorrente `when ... else` (Fluxo de Dados).
*   Essa abordagem avalia as condições sequencialmente (uma após a outra).
*   É muito mais legível que a lógica booleana pura, abstraindo as portas lógicas sob uma camada de decisão.
*   Lê-se: "A saída Y recebe X(0) quando o seletor for '00', caso contrário..."

### 3. Arquitetura: `v_WITH_SELECT` (Atribuição Selecionada)
Utiliza a instrução concorrente `with ... select`.
*   Funciona de forma semelhante a um `switch/case` das linguagens de software. 
*   Todas as opções são avaliadas simultaneamente com base no valor de `Sel`.
*   **Nota Importante (`when others`):** Em VHDL, é obrigatório cobrir todos os estados possíveis de um sinal em um bloco de seleção. Como o código utiliza vetores, o compilador exige a cláusula `others` para a última opção de roteamento, garantindo que não haverá valores não previstos (como estados de alta impedância ou indefinições do simulador) gerando inferências incorretas de hardware. Na aula do dia 28/05/2026 é abordado justamente esse tipo de inferência incorreta de hardware

