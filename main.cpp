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
  Cliente ac ("Jacu","11","rua mae do jose","231231123");
  Cliente ad ("Pirocao","11","rua mae","231123");
  a.setCliente(b);
  a.setCliente(ac);
  a.setCliente(ad);
  a.criar_conta(ad);
  a.criar_conta(b);
  a.criar_conta(ac);
  //a.excluir_conta(2);
  a.get_clientes();
  a.get_contas();
  // a.deposito(1,100);
  // a.saldo(1);
  // a.deposito(2,2);
  // a.saldo(2);
  // a.deposito(3,50);
  // a.saldo(3);
  // cout<<"-------------------------------------------"<<endl;
  // a.tarifa();
  // a.saldo(2);
  // a.saque(1,10);
  // a.saldo(1);
  // a.saque(1,10);
  // a.saldo(1);
  // a.saque(3,10);
  // a.saldo(3);
  // a.debitar_cpmf();
  // a.saldo(1);
  // a.saldo(2);
  // a.saldo(3);


  // /cb.creditar(10,"Ted");
  //  cb.print();
  // // cb.debitar(10,"toma");
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