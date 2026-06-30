
# Declarações
A = [2 -3 1; 4 -6 -1; 1 2 1];
B = [-5; -7; 4];
M = [A B];

# Tamanho da matriz
[l c] = size(A);

# Reduzindo a matriz com pivoteamento
for j=1:c-1 # coluna
  # Verificação para subir o maior valor em módulo
  # Fazemos a troca da linha para evitar divisão por zero

  maior = max(abs(M(j:end,j)));
  LinhaPermuta = j-1+find(abs(M(j:end,j)) == maior)

  aux = M(j,:);
  M(j,:) = M(LinhaPermuta,:);
  M(LinhaPermuta,:) = aux

  for i=j+1:l # linha
    a = M(i,j)/M(j,j); # pivo
    M(i,:) = M(i,:) - (a)*M(j,:); # metodo
  end

  M
end

# Dividindo pela diagonal principal
for i=1:l
  M(i,:) = M(i,:)/M(i,i);
end


## inicio:incremento:fim
## equivale a for(int i = l-1; i>=1; i--)

# Validação do processo
for i=l-1:-1:1
  s=0;
  for j=l:-1:i+1;
    s = s+M(j,c+1)*M(i,j);
  end
  M(i,c+1) = M(i,c+1) - s;
end

solucao = M(:,c+1)