% Método da interpolação de lagrange
% como a questão pediu de ordem 3, precisamo de 4 pontos para formar o polinomio cubico
% Usando os 4 pontos mais próximos de 0.25 (0.1, 0.2, 0.3, 0.4)

X = [0.1, 0.2, 0.3, 0.4]; 
Y = [1.0718, 1.1487, 1.2311, 1.3195]; % Corrigido o valor de 0.3
x_alvo = 0.25;
n = length(X); 
Px = 0;

for i = 1:n
    Li = 1; 
    for j = 1:n
        if i ~= j 
            numerador = x_alvo - X(j);
            denominador = X(i) - X(j);
            Li = Li * (numerador / denominador);
        end
    end
    Px = Px + Y(i) * Li;
end

Px 