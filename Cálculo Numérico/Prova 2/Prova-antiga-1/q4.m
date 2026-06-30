f=@(x)(x.*x)./(x-2);

a=0;
b=1;
h=0.1;
p=[a:h:b];
n_trapezios = (b-a)/h;

s = 0;

for i=2:n_trapezios
    x_a = p(i);
    s=s+f(x_a);
end

area_total = (h/2)*(f(a)+2*s+f(b))