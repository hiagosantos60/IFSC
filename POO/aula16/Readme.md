# Associações

## Exercício 1
``` mermaid
classDiagram
    class Aviao {
        - maxPassageiros : int
        - maxTripulantes : int
        - pesoMaximo : double
        - capacidadeCombustivel : double
        - qtdMotores : int
        - motores : ArrayList~Motor~
        + Aviao(int maxPassageiros, int maxTripulantes, double maxPeso, double maxCapacidade, int qtdMotores, String tipoMotor, double consumoMotor)
    }

    class Motor {
        - tipo : String
        - ligado : boolean
        - consumo : double
        + Motor(String tipoMotor, double consumoMotor)
    }

    Aviao"1" *-- "1..8"Motor

``` 