#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include "conta.h"
#include "cliente.h"

class Contacorrente: public Conta{
private:
    double limitecredito_;

public:
    Contacorrente(Cliente c, double lim): Conta(c),limitecredito_(lim){};
    bool debitar(double v,string d);
    ~Contacorrente();
};



#endif //CONTACORRENTE_H