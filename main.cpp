#include <iostream>
#include <list>
#include <string>
#include <ctime>
#include "conta.h"
#include "cliente.h"
#include "movimentacao.h"
using namespace std;

int main(){
    Cliente *a = new Cliente("Joaoa","121212","Rua do joao","33333333");
    Conta ca(a);

    ca.creditar(10,"ted enviada");
    ca.print();
    cout << endl << endl;
    Cliente b;
    b.setNome("Paulo");
    b.setCpf_cnpj("115654879622");
    b.setEndereco("rua a");
    b.setFone("998745632545");

    Conta cb(&b);

    cb.creditar(10,"Ted");
    cb.print();
    cb.debitar(10,"toma");
    cb.print();


}
