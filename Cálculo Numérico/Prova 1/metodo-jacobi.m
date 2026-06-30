% Método de Jacobi-Richardson 

a=[10 2 1; 1 5 1; 2 3 10];
b=[7; -8; 6];

%%DIVISÃO DAS MATRIZES PELO ELEMENTO DA DIAGONAL PRINCIPAL 
[m n]=size(a);
for i=1:m
    divisor = a(i,i);
    b(i,:) = b(i,:)/divisor;
    a(i,:) = a(i,:)/divisor;
    a(i,i) = 0;
end

%chute inicial 
x0 = [0;0;0];
x1 = b-a*x0;
erro = max(abs(x1-x0));

while(erro > 0.01) 
    x1 = b-a*x0;
    % Forma verbosa de fazer a atualização  
    % for i=1:size(a)
    %     x1(i) = b(i) - a(i,:)*x0;
    % end
    erro = max(abs(x1-x0));
    x0 = x1;
end

x1
x0

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%55

% 1. Funções anônimas usando vetores (facilita a manipulação)
F = @(x) [x(1)^2 + x(1)*x(2)^2 - 2; 
          x(1)*x(2) - 3*x(1)*x(2)^3 + 4];

% 2. Jacobiano (também recebendo um vetor x)
J = @(x) [2*x(1) + x(2)^2,      2*x(1)*x(2); 
          x(2) - 3*x(2)^3,     x(1) - 9*x(1)*x(2)^2];

% 3. Configurações iniciais
X = [1; 0];      % Chute inicial direto como vetor
erro = 1;        % Valor inicial para entrar no loop
tol = 1e-5;      % Tolerância mais rigorosa (opcional)
max_iter = 50;   % Segurança para evitar loop infinito
iter = 0;

% 4. Loop de Newton
while (erro > tol && iter < max_iter)
    X0 = X;
    
    % Em vez de inv(J)*F, usamos J \ F
    % Isso resolve: J * DeltaX = -F
    delta = J(X0) \ (-F(X0)); 
    
    X = X0 + delta;
    
    % Usando a norma para o erro (mais comum em cálculo numérico)
    erro = norm(X - X0);
    iter = iter + 1;
end

fprintf('Solução encontrada em %d iterações:\n', iter);
disp(X);
