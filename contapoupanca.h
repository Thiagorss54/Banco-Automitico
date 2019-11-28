#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H
#include "movimentacao.h"

class Contapoupanca:public Conta{
    private:
        double Poupanca[28];
    public:
        Contapoupanca(Cliente c):Conta(c){}
        void Credito_Poupanca(double valor);
        void Debito_Poupanca(double valor);
        void Rendimento_Poupanca();
        double getSaldo(int dia){ return Poupanca[dia - 1]; }
};

#endif