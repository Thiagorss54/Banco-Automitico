#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

class Contacorrente: public Conta{
private:
    double limitecredito;

public:
    Contacorrente(Cliente c, double lim): Cliente(c),limitecredito(lim);
    ~Contacorrente();
};



#endif //CONTACORRENTE_H