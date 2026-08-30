# Diagrama atual
``` mermaid
classDiagram
    Carta --* App
    Naipe -- Carta
    Valor -- Carta
    CartaGrafica --|> Carta
    App ..> Drawlistener
    CartaGrafica ..> Draw
    Draw ..* App
```

# Diagrama ajustado para flexibilidade
``` mermaid
classDiagram
    direction LR

    App ..> DrawListener
    ElementoGrafico ..> Draw
    Dado <|-- DadoGUI
    Carta <|-- CartaGUI
    DadoGUI ..|> ElementoGrafico
    CartaGUI ..|> ElementoGrafico
    App *-- ElementoGrafico

    class ElementoGrafico{
        <<interface>>
        + desenhar(Draw d)
    }

    class CartaGUI {
        - x: double
        - y: double
        + virarCarta()
        + clicouDentro
    }

    class DadoGUI{
        - x: double
        - y: double
    }

    class Dado {
        - valorFace int
        - numeroDeFaces int
        - ArrayList<> estatisticas
        + gerarEstatisticas()
        + jogar()
    }

    class Carta {
        naipe: Naipes
        valor: Valor
    }


```