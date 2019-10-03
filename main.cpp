#include <iostream>
#include <list>
#include <string>
#include <ctime>
#include "conta.h"
#include "cliente.h"
#include "movimentacao.h"
#include "banco.h"
using namespace std;

int main(){

  Banco a("Banco nordeste");

  Cliente b;
  b.setNome("Paulo");
  b.setCpf_cnpj("115654879622");
  b.setEndereco("rua a");
  b.setFone("998745632545");

  a.setCliente(b);
  Conta cb(&b);

  a.setConta(cb);
  a.deposito(1,20);
  //
  // cb.creditar(10,"Ted");
  // cb.print();
  // cb.debitar(10,"toma");
  // cb.print();
  //
  // string ai = "2019", mi = "10", di = "04";
  // string af = "2019", mf = "10", df = "01";
  //
  // vector<string> d;
  // d.push_back(ai);
  // d.push_back(mi);
  // d.push_back(di);
  //
  // vector<string> d1;
  // d1.push_back(af);
  // d1.push_back(mf);
  // d1.push_back(df);


    return 0;

}
