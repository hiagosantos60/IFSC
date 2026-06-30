f=@(x) x^2+2*x-2;

#primeiro intervalo
a=0.4;
b=2;

erro = 1;
tolerancia = 0.0001;

# Aproximando por x 
while (erro > tolerancia)
    x=(a+b)/2;

    if(f(a)<0 && f(b)>0 && f(x)<0)
        a=x;
    end

    if(f(a)<0 && f(b)>0 && f(x)>0)
        b=x;
    end

    erro = abs(b-a);
end

display("Primeira raiz: ")
display(x) # x= 0.73

## Para encontrar a outra raiz 

#segundo intervalo
a=-3;
b=-2;

erro = 1;
tolerancia = 0.0001;

while (erro > tolerancia)
    x=(a+b)/2;

    if(f(a)>0 && f(b)<0 && f(x)>0)
        a=x;
    end

    if(f(a)>0 && f(b)<0 && f(x)<0)
        b=x;
    end

    erro = abs(b-a);
end

display("Segunda raiz: ")
display(x) # deve retornar x = -2.7320