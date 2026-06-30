% Definindo as funções para análise 
F = @(x,y) [x*x+x*y*y-2 ; x*y-3*x*y*y*y+4];

% Jacobiano
J = @(x,y) [2*x+y*y , 2*x*y ; y-3*y*y*y , x-9*x*y*y];

% chute inicial
X0 = [1;0];
x = X0(1); % guardando x  
y = X0(2); % guardando y

% primeira interação do método
X = X0 - inv(J(x,y))*F(x,y);

erro = sum(abs(X-X0));

while (erro>0.1)
    
  % vai para o proximo valor
  X0 = X;
  x = X0(1);
  y = X0(2);

  % calcula novamente o proximo valor
  X = X0 - inv(J(x,y))*F(x,y);

  % calculo da norma 1 (distancia entre dois pontos)
  erro = sum(abs(X-X0));
  % repete
end

X