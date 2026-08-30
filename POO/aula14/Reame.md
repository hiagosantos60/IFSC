# Diagrama de classes UML
- Exemplo de uma classe
``` mermaid 
classDiagram 
    direction LR

    class Retangulo {
        - int altura
        - int largura
        + Retangulo(int a, int l)
        + getArea() int
    }
```

# Carros
- Exemplo 2
``` mermaid
---
config:
    rankSpacing : 100
---
classDiagram
    direction LR

    class Carro {
        - marca : String
        - propulsor : Motor
        + Carro()
        + acelerar(int v) void
    }

    class Motor {
        - hp : int
        - giroAtual : int
        - cilindros : int
        + Motor()
        + acelerar(v int) void
    }

    class Roda{
        - diametro : double
        - material : String
        - calibragem : double
        + Roda()
    }

    Carro"1" o-- "1"Motor  
    Carro"1" o-- "3..4"Roda
```


# Livros
- Exemplo 3
``` mermaid
---
config:
    rankSpacing : 100
---
classDiagram
    direction LR

    class Livro {
        - titulo : String
        - autor : Pessoa
        - capitulos : Arraylist<Capitulos>
        + Livro(t: String, a:Pessoa)
        + adicionarCapitulo(t: String) void
        + imprimir() void
    }

    class Capitulo {
        - titulo : String
        + Capitulo(t: String)
    }

    
    Livro"1" o-- "1.."Capitulo
```