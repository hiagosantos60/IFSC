% 1. Seus dados
x = [-0.95, -0.65, -0.35, -0.05, 0.25, 0.55, 0.85, 1.15, 1.45];
y = [-2.57, -2.01, -1.61, -1.42, -1.33, -1.33, -1.48, -1.85, -2.38];

% 2. Montar a conta (o sistema de 3 equações)
% A é a tabela com as somas, B é o resultado das somas
n = length(x);

A = [sum(x.^4) sum(x.^3) sum(x.^2);
     sum(x.^3) sum(x.^2) sum(x);
     sum(x.^2) sum(x)    n];

B = [sum(x.^2 .* y); sum(x .* y); sum(y)];

% 3. Resolver a conta
% K = inv(A)*B
K = A \ B;
a = K(1); b = K(2); c = K(3);

% 4. Desenhar o gráfico
% Cria uma linha suave entre o menor e o maior x
dominio = [min(x):0.1:max(x)];
imagem = a*(dominio.^2) + b*dominio + c;

plot(x, y, '*', dominio, imagem, '-')