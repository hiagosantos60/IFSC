# Flip-Flop D com Reset Assíncrono e Habilitação (Enable)

Este projeto implementa um elemento de memória sequencial básico: um **Flip-Flop do tipo D** sensível à borda de subida do clock (`rising_edge`), contendo as funcionalidades adicionais de **Reset Assíncrono** e **Habilitação de Escrita (Enable)**.



## Propósito do Circuito

O Flip-Flop D armazena o estado do bit de entrada `d` e o transfere para a saída `q` sob condições específicas controladas por clock, reset e enable:

*   **`clk`** (Input): Sinal de clock do sistema. O circuito reage apenas na transição de nível baixo para nível alto (borda de subida).
*   **`rst`** (Input): Sinal de reset assíncrono. Quando em nível alto (`1`), zera imediatamente a saída, independentemente do clock.
*   **`enable`** (Input): Sinal de validação. Se estiver em `1` na borda do clock, o dado `d` é salvo. Se estiver em `0`, o circuito ignora a entrada e mantém o dado anterior.
*   **`d`** (Input): Dado de entrada a ser armazenado.
*   **`q`** (Output): Saída que reflete o estado interno armazenado.

---

## Funcionamento e Prioridades Lógicas

Dentro do bloco `process(clk, rst)`, a lógica segue uma hierarquia estrita de prioridades baseada na estrutura `if/elsif`:

1.  **Prioridade Máxima (Reset Assíncrono):** A primeira condição checada é `if rst = '1'`. Como o sinal `rst` está presente na lista de sensibilidade do processo, qualquer mudança nele dispara o bloco imediatamente. Se ativado, o circuito ignora o clock e zera o registrador interno (`estadoAtual <= '0'`).
2.  **Segunda Prioridade (Borda de Clock):** Caso o reset esteja desativado (`'0'`), o circuito aguarda o próximo evento de borda de subida do clock (`rising_edge(clk)`).
3.  **Controle de Fluxo (Enable):** Uma vez na borda do clock, o sinal `enable` é avaliado. Se for `1`, o valor de `d` é capturado.

