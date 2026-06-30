% O método de simpson é baseado em pontos, podemos ter a função ou os pontos 

h = 2;
v = [0, 16.8, 42.4, 76.8, 120, 172, 232.8, 302.4, 380.8, 468, 564];

soma_impares = sum(v(2:2:end-1));
soma_pares   = sum(v(3:2:end-2));

area_total = (h/3) * (v(1) + 4*soma_impares + 2*soma_pares + v(end))