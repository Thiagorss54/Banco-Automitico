#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "cliente.h"
#include "conta.h"

using namespace std;
class Contapoupanca: public Conta{
    private:
        double Poupanca[28];
    public:
        Contapoupanca(Cliente c);
        Contapoupanca(int nconta,Cliente c,list<Movimentacao> m, double sald[28]);
        void creditar(double valor,string d);
        bool debitar(double valor,string d);
        bool debitar(double valor,Movimentacao mov);
        void Rendimento_Poupanca();
        double getSaldo(int dia){ return Poupanca[dia - 1]; }
};

#endif