# MÉTODO DE Runge-Kutta
# EXEMPLO DE IMPLEMENTAÇÃO QUANDO SABEMOS A RESPOSTA DA EDO

clear all; close all; clc;

ERRO = size(10);
Hs = size(10);

f = @(x, y) y;

for j = 1 : 10
  h = 0.5 / (2^j);
  x = [0 : h : 1];
  y = zeros(size(x));

  y(1) = 1;

  for i = 2 : size(y,2)
    k1 = f(x(i-1), y(i-1));
    k2 = f(x(i-1) + 0.5*h, y(i-1) + 0.5*h*k1);
    k3 = f(x(i-1)+0.5*h, y(i-1) + 0.5*h*k2);
    k4 = f(x(i-1)+h, y(i-1)+h*k3);
    y(i) = y(i-1) + (h/6)*(k1 + 2*k2 + 2*k3 + k4);
    final = y(i);
  endfor
  final;
  erro = max(abs(e - y(end)));

  ERRO(j) = erro;
  Hs(j) = h;

endfor

final

plot(Hs, ERRO);
LogHs = log(Hs);
LogERRO = log(ERRO);
plot(log(Hs), log(ERRO))
deltaERRO = (LogERRO(end) - LogERRO(1))
deltaHs = LogHs(end) - LogHs(1)
coeficiente = deltaERRO / deltaHs'