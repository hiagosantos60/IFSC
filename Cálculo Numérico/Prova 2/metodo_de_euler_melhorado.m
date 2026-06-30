clear all; close all; clc;

num_testes = 10;

% Vetores para armazenar resultados para a análise
ERRO = zeros(1, num_testes);
Hs   = zeros(1, num_testes);

% definição da EDO: y' = y
f = @(x, y) y;

for j = 1 : num_testes
    % A cada loop, diminui o tamanho do passo 'h' pela metade
    h = 0.1 / (2^j);
    % Definindo o domínio (caminhando de 0 até 1, dando passos de tamanho h)
    x = 0 : h : 1;
    y = zeros(size(x));
    % Condição inicial: Sabemos que e^0 = 1 (quando x=0, y=1)
    y(1) = 1;

    for i = 2 : length(x)
        x_atual = x(i-1);
        y_atual = y(i-1);

        % Calcula a inclinação no inicio do intervalo (k1)
        k1 = f(x_atual, y_atual); 

        % Verifica o futuro e calcula a inclinação no FIM do intervalo (k2)
        k2 = f(x_atual + h, y_atual + h * k1); 

        % Dá o passo real usando a média das inclinações
        y(i) = y_atual + (h / 2) * (k1 + k2); 
        
    end
    % coleta dos dados obtidos pelo método
    resultado_esperado = exp(1); 
    resultado_alcancado = y(end);

    % O erro é a diferença absoluta entre o esperado e o alcançado
    erro_maximo = abs(resultado_esperado - resultado_alcancado);

    ERRO(j) = erro_maximo;
    Hs(j) = h;

end
% Calculo da ordem do método e resultaod
% Aplica logaritmo natural nos vetores para transformar a curva em reta
LogHs = log(Hs);
LogERRO = log(ERRO);

% Calcula a inclinação da reta (o coeficiente angular m = deltaY / deltaX)
deltaERRO = LogERRO(end) - LogERRO(1);
deltaHs   = LogHs(end) - LogHs(1);

coeficiente = deltaERRO / deltaHs;

% Exibe o resultado final no console (esperado algo próximo a 2)
fprintf('A ordem de convergência (coeficiente) do Euler Melhorado é: %.4f\n', coeficiente);
figure(1);
plot(LogHs, LogERRO, '-o', 'LineWidth', 2, 'MarkerFaceColor', 'b');
title('Análise de Convergência - Método de Euler Melhorado');
xlabel('Logaritmo do Tamanho do Passo: log(h)');
ylabel('Logaritmo do Erro Máximo: log(Erro)');
grid on;