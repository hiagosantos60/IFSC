% Definição da função
f = @(x) x.*x.*x;

% Intervalo de integração
a = 0; 
b = 2;
n = 100;

h = (b - a) / n; % 0,02

ponto = [a:h:b]; % [a=0 ,i1= 0.02, i2 = 0.04,...,i98 = 1.96, i99 = 1.98, b=2]

soma_impares = sum(f(ponto(2:2:end-1))); % i2,i4,i6,i8...

soma_pares = sum(f(ponto(3:2:end-2))); % i3,i5,i7,i9...

area = (h / 3) * (f(ponto(1)) + 4 * soma_impares + 2 * soma_pares + f(ponto(end)));

disp('Resultado da Integral:');
disp(area);