#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include "conta.h"
#include "cliente.h"

class Contacorrente: public Conta{
private:
    double limitecredito_;

public:
    Contacorrente(Cliente c, double lim = 0): Conta(c),limitecredito_(lim){};
    Contacorrente(int nconta,double sald,Cliente c,list<Movimentacao> m, double lim);
    bool debitar(double v,string d);
    bool debitar(double v,Movimentacao mov);
    double lim_cred(){return limitecredito_;}
	

    ~Contacorrente();
};



#endif //CONTACORRENTE_H