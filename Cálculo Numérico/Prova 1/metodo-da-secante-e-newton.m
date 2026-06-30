# MÉTODO COM DERIVADAS

% FUNÇÃO E DERIVADA
f = @(x) x^2 + 2*x - 2;
df = @(x) 2*x + 2;

% CONFIGURAÇÕES INICIAIS
chute entre [0,1], também podemos testar com outro intervalo
x1 = 0.5; 
tolerancia = 0.0001;
erro = 1;

while (erro > tolerancia)
    x2 = x1 - f(x1)/df(x1);
    
    erro = abs(x2 - x1);
    x1 = x2;
    
end

display(x1);

##################################################

# MÉTODO SEM DERIVADAS - MÉTODO DA SECANTE

f = @(x) x^2 + 2*x - 2;

x0 = 0.9;   % Primeiro chute
x1 = 1;   % Segundo chute
tolerancia = 0.0001;
erro = 1;

while (erro > tolerancia)
    % FÓRMULA DA SECANTE
    x_novo = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
    
    erro = abs(x_novo - x1);
    
    % ATUALIZAÇÃO DOS PONTOS
    x0 = x1;     % O x1 antigo vira o novo x0
    x1 = x_novo; % O resultado atual vira o novo x1
    
end

display(x1);