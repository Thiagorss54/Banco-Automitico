#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include "conta.h"
#include "cliente.h"

class Contacorrente: public Conta{
private:
    double limitecredito_;

public:
    Contacorrente(Cliente c, double lim = 0): Conta(c),limitecredito_(lim){};
    bool debitar(double v,string d);
    bool debitar(double v,Movimentacao mov);
	

    ~Contacorrente();
};



#endif //CONTACORRENTE_H