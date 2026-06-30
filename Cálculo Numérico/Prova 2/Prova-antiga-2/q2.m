% é uma equação de segundo grau
x = [-0.950, -0.650, -0.350, -0.050, 0.250, 0.550, 0.850, 1.150, 1.450];
y = [-2.5693, -2.0106, -1.6086, -1.4191, -1.3293, -1.3273, -1.4820, -1.8511, -2.3839];

A = [ sum(x.^4), sum(x.^3), sum(x.^2) ;
      sum(x.^3), sum(x.^2), sum(x)    ;
      sum(x.^2), sum(x),    length(x) ];

b = [ sum(y .* (x.^2)) ; 
      sum(y .* x)      ; 
      sum(y)           ];

c = A \ b; 

x_alvo = 0.3;
f_aproximado = c(1)*x_alvo^2 + c(2)*x_alvo + c(3);