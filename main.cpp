#include <iostream>
#include <list>
#include <string>
#include <ctime>
#include "conta.h"
#include "cliente.h"
#include "movimentacao.h"
using namespace std;

int main(){

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

    string ai = "2019", mi = "10", di = "02";

    vector<string> d;
    d.push_back(ai);
    d.push_back(mi);
    d.push_back(di);
    list<Movimentacao> a = cb.extrato(d);
    cout << a.type() << endl;

}
