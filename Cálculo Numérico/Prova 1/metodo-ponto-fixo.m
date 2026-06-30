% FUNÇÃO: f(x) = x^2 + 2x - 2
% as derivadas em phi_um e phi_dois

% PRIMEIRO CHUTE (Intervalo 0 a 1)
chute_um = 0.9;
phi_um = @(x) 2 / (x + 2);

% SEGUNDO CHUTE (Intervalo -3 a -2)
chute_dois = -2.9;
phi_dois = @(x) -sqrt(2 - 2*x); 

erro_um = 1;
erro_dois = 1;
tolerancia = 0.0001;

while (erro_um > tolerancia || erro_dois > tolerancia)
  
  if (erro_um > tolerancia)
    prox_chute_um = phi_um(chute_um);
    erro_um = abs(prox_chute_um - chute_um);
    chute_um = prox_chute_um;
  end

  if (erro_dois > tolerancia)
    prox_chute_dois = phi_dois(chute_dois);
    erro_dois = abs(prox_chute_dois - chute_dois);
    chute_dois = prox_chute_dois;
  end

end

printf('Raiz 1 (Positiva) aproximada: %.4f\n', chute_um) 
printf('Raiz 2 (Negativa) aproximada: %.4f\n', chute_dois)