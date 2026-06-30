f = @(x) exp(- (x.^2) / 2) / sqrt(2 * pi);

a = -1;
b = 1;
h = 0.1;
p = [a:h:b];

soma_impares = sum(f(p(2:2:end-1))); 
soma_pares = sum(f(p(3:2:end-2)));

probabilidade = (f(a) + 4*soma_impares + 2*soma_pares + f(b))*(h/3)