#include <iostream>
#include <list>
#include <string>
#include <ctime>
#include "conta.h"
#include "cliente.h"
#include "movimentacao.h"
#include "banco.h"
#include "interface.h"
#include "contacorrente.h"
using namespace std;

int main(){


  //  string nB = "  BANCO ";
  //  Interface I(nB);
  //  I.main();


  // a.ler_dados();
  Cliente b;
  b.setNome("Paulo");
  b.setCpf_cnpj("115654879622");
  b.setEndereco("rua a");
  b.setFone("998745632545");
  Cliente ac ("Jacu","11","rua mae do jose","231231123");

  double lim = 300;

  Contacorrente a(b,lim);
  
 Contapoupanca dd(ac);

  
  Contacorrente cc(ac,lim);
  
  Banco banco("Foda-se");
  banco.setConta(dd);
  banco.setConta(cc);
  banco.setConta(a);
  banco.deposito(1,100);
  banco.deposito(2,100);
  //banco.saldo(1);
  banco.saldo(2);
  // banco.saque(2,15);
  // banco.saldo(2);
  void transferencia_conta(int conta_origem, int conta_destino,double valor);
  banco.transferencia_conta(1,2,50);
  // banco.saldo(1);
  // banco.saldo(2);
   banco.tarifa();
  // banco.saldo(1);

  // d/ouble sal = a.getSaldo();
  // cout<< sal << endl; 
  // Cliente ad ("Pirocao","11","rua mae","231123");
  // a.setCliente(b);
  // a.setCliente(ac);
  // a.setCliente(ad);
  // a.criar_conta(ad);
  // a.criar_conta(b);
  // a.criar_conta(ac);


//   list<Conta> con = a.get_contas();
//   cout<<con.size()<<endl;
//   a.saldo(1);
//   a.saldo(2);
//   a.saldo(3);
//   a.saque(1,20);
//   a.saldo(1);
//   cout<<"-----------"<<endl;
//   a.excluir_cliente("115654879622");
  
  // a.gravar_dados();

  // a.deposito(1,100);
  // a.saldo(1);
  // a.deposito(2,2);
  // a.saldo(2);
  // a.deposito(3,50);
  // a.saldo(3);
// //    cout<<"-------------------------------------------"<<endl;
// //   // a.tarifa();
//   a.transferencia_conta(1,2,20);
  //
  // cout<<"------------------"<<endl;
  //
  //
  //
  //

  // Conta cb(&b);
  // cout << "\t\t\tINICIO DE CREDITAR" << endl;
  // // cb.creditar(10,"Ted");
  // // cb.print();
  // // //cb.debitar(10,"toma");
  // // cb.print();
  //
  //
  string ai = "2019", mi = "10", di = "06";
   string af = "2019", mf = "10", df = "01";
  string datainicial = "20191004";
  string datafinal = "20191001";
  vector<string> d;
  d.push_back(ai);
  d.push_back(mi);
  d.push_back(di);
  vector<string> d1;
  d1.push_back(af);
  d1.push_back(mf);
  d1.push_back(df);
  
  banco.extrato(2,d);


  return 0;

}
