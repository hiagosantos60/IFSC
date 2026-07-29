# Comparador de Magnitude de 8 Bits: Estudo de Inferência de Latch em VHDL

Este projeto implementa um comparador de magnitude de 8 bits para números com sinal (`signed`). O objetivo principal deste código é puramente didático e técnico: demonstrar o fenômeno da **inferência indesejada de Latches** em circuitos combinacionais descritos em VHDL, mostrando como esse problema ocorre e quais são as duas abordagens padrão para corrigi-lo.

---

## Propósito do Circuito

O circuito (`atribuicao_sequencial`) possui duas entradas de 8 bits (`a` e `b`) e três saídas de 1 bit:
*   **`gt`** (Greater Than): Fica em nível alto (`1`) se $a > b$.
*   **`eq`** (Equal): Fica em nível alto (`1`) se $a = b$.
*   **`lt`** (Less Than): Fica em nível alto (`1`) se $a < b$.

---

## O Problema: Inferência de Latch

Em lógica combinacional pura, as saídas devem depender exclusivamente das entradas atuais. Se você descreve um comportamento dentro de um `process` e deixa de cobrir o estado de uma saída em **qualquer** que seja o caminho lógico (ramificação do `if/else`), o sintetizador de hardware é forçado a assumir que aquela saída deve manter o valor anterior. Ou seja, se ele não sabe como deve se comportar com aquele valor e não há nada que deixe explícito o que ele deve fazer, o sintetizador irá inferior uma latch para armazenar aquele valor. Isso também se justifica por não haver um clock, então para gerar o hardware assim mesmo, ele faz essa manobra.

### Por que Latches são um problema no projeto digital?
1. **Glitches e Instabilidade:** Latches são sensíveis a nível, tornando o circuito propenso a falhas transientes por atrasos de propagação.
2. **Análise de Tempo (STA):** Ferramentas de temporização têm enorme dificuldade em analisar caminhos que contêm latches combinacionais, o que pode inviabilizar o projeto em FPGAs/ASICs.
3. **Desperdício de Recursos:** Latches consomem elementos de lógica extras de forma desnecessária.

---

## Arquiteturas Implementadas

O projeto apresenta três formas de resolver o mesmo problema, evidenciando o erro e as correções:

### 1. `atribuicao_incorreta`
Nesta arquitetura, se `a_signed > b_signed`, a saída `gt` recebe `1`. Porém, o código **não diz** o que acontece com `eq` e `lt` dentro desse bloco. 
*   **Resultado:** Uma vez que `eq` ou `lt` forem para `1`, eles nunca mais voltarão para `0`. O sintetizador infere 3 latches para segurar esses valores.

### 2. `atribuicao_correta_1`
Corrige o problema definindo explicitamente o estado de **todas** as saídas em **todas** as ramificações do `if`.
```vhdl
if (a_signed > b_signed) then
    gt <= '1'; 
    eq <= '0'; 
    lt <= '0'; -- Todos os sinais cobertos!
.
.
.

```

### 3. `atribuicao_correta_v2` (Abordagem Explícita) 
Corrige o problema inicialiando tudo em zero e adicionando valor de acordo com o necessário para aquela condição em si.
``` vhdl
gt <= '0';
eq <= '0';
lt <= '0';
	
if (a_signed > b_signed) then
    gt <= '1';
.
.
.
```