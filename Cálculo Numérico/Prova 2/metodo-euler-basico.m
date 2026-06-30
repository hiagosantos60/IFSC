h = 0.1;               % Passo
x = [0 : h : 2];       % Domínio até 2
y = zeros(size(x));    % Vetor para guardar os resultados
y(1) = 1;              % Condição inicial: y(0) = 1

% O loop de cálculo
for i = 2 : length(x)
    % A REGRA DA DERIVADA: y' = -2 * y
    derivada = -2 * y(i-1); 
    
    % Aplicando o Método de Euler: y_novo = y_atual + h * derivada
    y(i) = y(i-1) + h * derivada;
end

% Comparação com a solução exata (e^(-2x))
plot(x, y, 'o-', x, exp(-2*x), 'r-');
legend('Aproximação Euler', 'Solução Exata');