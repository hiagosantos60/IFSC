% Método que serve para aproximar funções dado um conjunto de pontos

% Você define os pontos aqui. O código se ajusta ao tamanho dos vetores.
X = [1, 2, 4]; 
Y = [2, 3, 1];
x_alvo = 3; % O valor que queremos encontrar

n = length(X); % Descobre quantos pontos existem (neste caso, 3)
Px = 0;        % Inicializa o resultado final

for i = 1:n
    % Começamos o Li como 1 para cada novo ponto do somatório
    Li = 1; 
    
    for j = 1:n
        % Não pode dividir por zero
        if i ~= j 
            % Monta a fração multiplicando o que já existe pelo novo termo
            % Li = Li * [(x - xj) / (xi - xj)]
            numerador = x_alvo - X(j);
            denominador = X(i) - X(j);
            
            Li = Li * (numerador / denominador);
        end
    end
    
    % Após calcular o Li completo, multiplicamos pelo Yi e somamos ao Px
    Px = Px + Y(i) * Li;
end

fprintf('Resultado da interpolação dinâmica para x = %0.1f: %.4f\n', x_alvo, Px);