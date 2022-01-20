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


   string nB = "  BANCO ";
   Interface I(nB);
   I.main();


  // a.ler_dados();
//   Cliente b;
//   b.setNome("Paulo");
//   b.setCpf_cnpj("115654879622");
//   b.setEndereco("rua a");
//   b.setFone("998745632545");


//   double lim = 300;

//   Contacorrente a(b,lim);
  
//  Contapoupanca dd(ac);

  
//   Contacorrente cc(ac,lim);
  
  //Banco banco("BANCO");

 // banco.ler_dados();
  // cout<<"aqui"<<endl;
  // list<Contapoupanca> c = banco.get_contaspoupanca();
  // banco.saque(7,10);
  // banco.saldo(7);

  // // cout<<"deu"<<endl;
  // // list<Cliente> c = banco.get_clientes();
  // // list<Contacorrente> cc = banco.get_contascorrente();
  // Cliente ac ("Josue","11","avenida amazonas","231231123");
  // Contacorrente cc(ac,400);
  // banco.setConta(cc);
  // Cliente acc ("Breno","111145","avenida do contorno","231123");
  // Contapoupanca cp(acc);
  // banco.setCliente(acc);
  // banco.setConta(cp);


  // banco.setConta(cp);
  // banco.deposito(7,30);

  // banco.setCliente(ac);
  // banco.setConta(a);
  //   list<Contacorrente> ccc = banco.get_contascorrente();
  //banco.gravar_dados();

//   banco.setConta(dd);
//   banco.setConta(cc);
//   banco.setConta(a);
//   banco.deposito(1,100);
//   banco.deposito(2,100);
//   //banco.saldo(1);
//   banco.saldo(2);
//   // banco.saque(2,15);
//   // banco.saldo(2);
//   void transferencia_conta(int conta_origem, int conta_destino,double valor);
//   banco.transferencia_conta(1,2,50);
//   // banco.saldo(1);
//   // banco.saldo(2);
//    banco.tarifa();
//   // banco.saldo(1);

//   // d/ouble sal = a.getSaldo();
//   // cout<< sal << endl; 
//   // Cliente ad ("Pirocao","11","rua mae","231123");
//   // a.setCliente(b);
//   // a.setCliente(ac);
//   // a.setCliente(ad);
//   // a.criar_conta(ad);
//   // a.criar_conta(b);
//   // a.criar_conta(ac);


// //   list<Conta> con = a.get_contas();
// //   cout<<con.size()<<endl;
// //   a.saldo(1);
// //   a.saldo(2);
// //   a.saldo(3);
// //   a.saque(1,20);
// //   a.saldo(1);
// //   cout<<"-----------"<<endl;
// //   a.excluir_cliente("115654879622");
  
//   // a.gravar_dados();

//   // a.deposito(1,100);
//   // a.saldo(1);
//   // a.deposito(2,2);
//   // a.saldo(2);
//   // a.deposito(3,50);
//   // a.saldo(3);
// // //    cout<<"-------------------------------------------"<<endl;
// // //   // a.tarifa();
// //   a.transferencia_conta(1,2,20);
//   //
//   // cout<<"------------------"<<endl;
//   //
//   //
//   //
//   //

//   // Conta cb(&b);
//   // cout << "\t\t\tINICIO DE CREDITAR" << endl;
//   // // cb.creditar(10,"Ted");
//   // // cb.print();
//   // // //cb.debitar(10,"toma");
//   // // cb.print();
//   //
//   //
//   string ai = "2019", mi = "10", di = "06";
//    string af = "2019", mf = "10", df = "01";
//   string datainicial = "20191004";
//   string datafinal = "20191001";
//   vector<string> d;
//   d.push_back(ai);
//   d.push_back(mi);
//   d.push_back(di);
//   vector<string> d1;
//   d1.push_back(af);
//   d1.push_back(mf);
//   d1.push_back(df);
  
//   banco.extrato(2,d);


  return 0;

}
