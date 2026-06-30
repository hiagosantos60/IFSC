clear; close all; clc;

f = @(x) cos(x); 

% Intervalo e parâmetros
a = 0;
b = pi/2;
n_trapezios = 10;

% Tamanho da base de cada trapézio
h = (b-a)/n_trapezios;

% Criação do vetor de pontos 
ponto = [a : h : b];

somatorio_pontos_interno = 0;

% Somando apenas os pontos internos
for i = 2:n_trapezios 
    x_atual = ponto(i);
    somatorio_pontos_interno = somatorio_pontos_interno + f(x_atual);
end

% Aplicando a fórmula completa do método do trapézio
area_total = (h/2) * (f(a) + 2 * somatorio_pontos_interno + f(b));

fprintf('A área calculada é: %f\n', area_total);