# Relógios e cronômetros
Um relógio é um dispositivo que mede e exibe o tempo. Neste laboratório, você vai trabalhar com duas representações: relógio digital (hora em formato numérico) e relógio analógico (hora indicada por ponteiros). Para relógios digitais, você também vai implementar o comportamento de cronômetro, que pode ser:
- Progressivo: inicia em 00:00: 00 e avança a cada segundo
- Regressivo: inicia em um valor definido pelo usuário e reduz até 00:00:00

## Diagrama UML

``` mermaid
classDiagram

    Relogio <|-- RelogioAnalogico
    Relogio <|-- RelogioDigital
    RelogioDigital <|-- RelogioDigitalTexto
    RelogioDigital <|-- RelogioDigitalDisplay
    RelogioDigitalDisplay *-- Display


    class Relogio {
        <<Abstract>>
        # horas: int
        # minutos: int
        # segundos: int
        # posX: int
        # posY: int
        + avancarTempo()* void
        + desenhar(canvas: Draw)* boolean
        + setHorario() boolean
        + setHorarioManual(h: int, m: int, s: int) boolean
    }

    class RelogioDigital {
        <<Abstract>>
        # modo: int
        + static final int MODO_RELOGIO
        + static final int MODO_PROGRESSIVO
        + static final int MODO_REGRESSIVO
        + setModoRelogio(parametro de modo) boolean
    }

    class RelogioAnalogico {
        + RelogioAnalogico(x: int, y: int)
    }

    class RelogioDigitalTexto {
        - tamanhoFonte: int
        + RelogioDigitalTexto(x: int, y: int, fonte: int)
    }

    class RelogioDigitalDisplay {
        - tamanho: int
        - displays: Display[6]
        - static final int TAM_PEQUENO
        - static final int TAM_MEDIO
        - static final int TAM_GRANDE
        + RelogioDigitalDisplay(x: int, y: int, tamanho: int)
    }

    class Display {
        - segmentos: boolean[7]
        # setDigito(num: int) void
        + desenhar(canvas: Draw, x: int, y: int, tamanho: int) void
    }


```