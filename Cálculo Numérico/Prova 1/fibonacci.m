

x = 10;
a = 0;
b = 1;
c = 0;

while (x > 0)
  c = a+b;
  a = b;
  b = c;
  display(c)
  x--;
end