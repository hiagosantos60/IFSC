package engtelecom.poo;

public class Conta { 
    private long numConta;
    private double saldo;
    private String titular;


    public Conta(long numConta, double saldo, String titular) {
        if (setSaldo(saldo) == false) {
            return;
        } else this.saldo = saldo;

        this.numConta = numConta;
        this.titular = titular;
    }

    public boolean setSaldo(double valor) {
        if(valor < 0) {
            return false;
        } 
        this.saldo = valor;
        return true;
    }

    public double sacar(double valor) {
        this.saldo = (valor > saldo) ? 0 : saldo - valor;
        return this.saldo;
    }

    public double depositar(double valor) {
        this.saldo = (valor < 0) ? saldo : saldo + valor;
        return saldo;
    }

    public long getNumConta() {
        return numConta;
    }

    @Override
    public String toString() {
        return "Titular: " + titular + "\nNum Conta: " + numConta + "\nSaldo: " + saldo;
    }
}


