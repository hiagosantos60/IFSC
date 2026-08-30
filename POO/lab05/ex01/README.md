# Sistema de comércio eletrônico

> Um produto tem uma descrição, um preço e uma quantidade em estoque. Um cliente tem um nome, um e-mail e um ou mais endereços de entrega. Um cliente pode fazer um ou mais pedidos. Um pedido tem uma data, uma situação (pendente, pago, entregue, cancelado), um ou mais produtos, sendo que cada produto tem uma quantidade e um preço unitário.


## Modelagem UML

``` mermaid
    classDiagram

    Cliente "1" *-- "1..*" Endereco
    Pedido "1" o-- "1..*" Produto
    Pedido "1" --* "1" Cliente


    class Cliente {
        - nome: String
        - email: String
        - endereco: ArrayList~Endereco~
        - pedidos: ArrayList~Pedido~

        + Cliente(nome: String, email: String) boolena
        + adicionarEndereco(pais: String, estado: String, cidade: String, rua: String, numero: String, cep: string, complemento: String) boolean

        + criarPedido(data: LocalDate, status: String) boolean  
        + removerPedido(idPedido: int)

        + addProdutoNoPedido(idPedido: int, idProduto: int, qtd: int) boolean
        + removeProdutoNoPedido(idPedido: int, idProduto: int, qtd: int) boolean
    }

    class Endereco {
        - pais: String
        - estado: String
        - cidade: String
        - rua: String
        - numero: String
        - cep: String
        - complemento: String

        + Endereco(pais: String, estado: String, cidade: String, rua: String, numero: String, cep: string, complemento: String)
    }

    class Produto {
        - idProduto: int
        - descricao: String
        - valor: double
        - qtdEstoque: int

        + Produto(descricao: String, valor: double, qtdEstoque: int)
    }

    class Pedido {
        - idPedido: int
        - situacao: String
        - data: LocalDate
        - produtos: HashMap~Integer, Produto~

        + Pedido(data: LocalDate, status: String)
        + addProduto(idProduto: int, qtd: int) boolean
        + removeProduto(idProduto: int, qtd: int) boolean
    }

```