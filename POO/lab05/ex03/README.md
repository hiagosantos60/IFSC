# Sistema de gestão de frotas
> Uma empresa possui uma frota de veículos. Cada veículo tem um modelo, uma placa e um ano de fabricação. A empresa tem vários motoristas, e cada motorista pode dirigir um ou mais veículos. A empresa registra o uso de cada veículo, incluindo a data, o motorista e a distância percorrida.

``` mermaid

classDiagram
    direction LR
    Registro "1..*" o-- "1" Motorista
    Empresa "1..*" *-- "0..*" Registro
    Empresa "1..*" *-- "0..*" Motorista
    Empresa "1..*" *-- "0..*" Veiculo
    Registro "1..*" o-- "1" Veiculo
    

    class Veiculo {
        - modelo: String
        - placa: String
        - anoDeFabricacao: int
        + Veiculo(modelo: String, placa: String, anoDeFabricacao: int)
    }

    class Motorista {
        - nome: String
        - dataNasc: Localdate
        - categoriaCnh: String
        - cpf: int
        + Motorista(nome: String, dataNasc: Localdate, categoriaCnh: String)
        + mudarCategoria(novaCategoria: String) boolean
    }

    class Registro {
        - veiculo: Veiculo
        - motorista: Motorista
        - data: LocalDate
        - distancia: double
        + Registro(veiculo: Veiculo, motorista: Motorista, data: LocalDate, distancia: double)
    }

    class Empresa {
        - motoristas: HashMap~Motorista~
        - veiculos: HashMap~Veiculo~
        - registros: ArrayList~Regitro~
        - cnpj: int
        + Empresa (cnpj: int)
        + addMotorista(motorista: Motorista) boolean
        + addVeiculo(veiculo: Veiculo) boolean
        + addRegistro(registro: Registro) boolean
    }

```