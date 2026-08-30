# Agenda Telefonica

``` mermaid
classDiagram
    direction LR

    class App {
        - agenda : AgendaTelefonica
        + main()
        + menu()
    }

    class AgendaTelefonica {
        - contatos: ArrayList~Contato~
	
	    + isValido(int indice) boolean
        + findContato(String nome, String sobrenome, LocalDate dataNasc) Contato
        + addContato(Contato c) boolean
        + removeContato(int indiceContato) boolean

        + addEmail(String rotulo, String valor, int indiceContato) boolean
        + removeEmail(int indiceContato, int indiceEmail) boolean
        + updateEmail(int indiceContato, int indiceEmail, String rotulo, String valor) boolean

        + addTelefone(String rotulo, String valor, int indiceContato) boolean
        + removeTelefone(int indiceContato, int indiceTelefone) boolean
        + updateTelefone(int indiceContato, int indiceTelefone, String rotulo, String valor) boolean

        + listaContatos() void
    }

    class Contato {
        - emails: ArrayList~Email~
        - telefones: ArrayList~Telefone~
        - nome: String
        - sobrenome: String
        - dataNasc: LocalDate

        + Contato(String nome, String sobrenome, LocalDate dataNasc)

        + validarEmail(String valor) boolean
        + validarTelefone(String valor) boolean

        + addEmail(String rotulo, String valor) boolean
        + removeEmail(int indiceEmail) boolean
        + updateEmail(int indiceEmail, String rotulo, String valor) boolean

        + addTelefone(String rotulo, String valor) boolean
        + removeTelefone(int indiceTelefone) boolean
        + updateTelefone(int indiceTelefone, String rotulo, String valor) boolean

        + toString() String
    }

    class Telefone {
        - valor: String
        - rotulo: String

        + Telefone(String rotulo, String valor)
        + setValor(String valor)
        + setRotulo(String rotulo)
        + getValor() String
        + getRotulo() String
        + toString() String
    }

    class Email {
        - rotulo: String
        - valor: String

        + Email(String rotulo, String valor)
        + setValor(String valor)
        + setRotulo(String rotulo)
        + getValor() String
        + getRotulo() String
        + toString() String
    }

    App "1" *-- "1" AgendaTelefonica
    AgendaTelefonica "1" *-- "0..*" Contato
    Contato "1" *-- "0..*" Telefone
    Contato "1" *-- "0..*" Email
```