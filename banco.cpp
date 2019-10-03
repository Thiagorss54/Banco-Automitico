#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "conta.h"
#include "cliente.h"
#include "movimentacao.h"
#include "banco.h"

using namespace std;

Banco::Banco(string nBanco){
  nomeBanco = nBanco;
}

void Banco::setCliente(Cliente c) {
	listaClientes.push_back(c);
}

void Banco::setConta(Conta c){
	listaContas.push_back(c);
}
/*
void Banco::operator =(const Banco& c){
  this->nomeBanco = c.nomeBanco;
  this->listaClientes = c.listaClientes;
  this->listaContas = c.listaContas;
}

void Banco::delCliente(int id) {
	int a = 0;
	Cliente aux();
	for (list<Cliente>::iterator i = listaClientes.begin(); i != listaClientes.end(); i++) {
		if (id == i->Cpf_cnpj) {
			for (list<Conta>::iterator j = listaContas.begin(); j != listaContas.end(); j++) {
				if (*i == j->cliente) {
					a++;
				}
			}
			if (a == 0) {
				aux = *i;
			}else {
				cout << "O cliente não pode ser excluido pois ainda tem conta." << endl;
			}
		}else {
			cout << "O cliente não está cadastrado nesse banco." << endl;
		}
	}
	listaClientes.remove(aux);
}

void Banco::delConta(int num) {
	int a = 0;
	Cliente aux();
	for (list<Conta>::iterator i = listaContas.begin(); i != listaContas.end(); i++) {
		if(num == i->numConta) {
			aux = *i;
			a++;
		}
	}
	if(a == 0){
		cout << "A conta não existe." << endl;
	}
	else {
		listaContas.remove(aux);
	}
}
*/
void Banco::deposito(int nconta, double valor){
  for (auto j = listaContas.begin(); j != listaContas.end(); j++) {
    if(nconta == j->numConta){
      j->creditar(valor, "Deposito");
    }
  }
}

void Banco::saque(int nconta, double valor){

  for (auto j = listaContas.begin(); j != listaContas.end(); j++) {
    if(nconta == j->numConta){
      j->debitar(valor, "Saque");
    }
  }
}
void Banco::saque(int nconta, double valor, string ano, string mes, string dia){
  Movimentacao mov("Saque",'D',valor,ano,mes,dia);
  for (auto j = listaContas.begin(); j != listaContas.end(); j++) {
    if(nconta == j->numConta){
      j->debitar(valor,mov);
    }
  }
}


void Banco::transferencia_conta(int conta_origem, int conta_destino,double valor){
  for (auto j = listaContas.begin(); j != listaContas.end(); j++) {
    if(conta_origem == j->numConta){
      if(j->debitar(valor, "Transferencia entre contas")){
        for (auto j = listaContas.begin(); j != listaContas.end(); j++) {
          j->creditar(valor, "Transferencia entre contas");
        }
      }
      else{
        cout<<"Transacao nao pode ser realizada" << endl;
      }
    }
  }
}

void Banco::tarifa(){
  for (auto j = listaContas.begin(); j != listaContas.end(); j++) {
    j->debitar(15, "Cobranca de Tarifa");
  }
}

int rdn(int y, int m, int d) { /* Rata Die day one is 0001-01-01 */
  if (m < 3)
  y--, m += 12;
  return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}

void Banco::debitar_cpmf(){

  vector<string> opa ;
  time_t rawtime;
  string x;
  struct tm * timeinfo;
  char buffer [80];
  time (&rawtime);
  timeinfo = localtime (&rawtime);
  strftime (buffer,80,"%Y",timeinfo);
  x = buffer;
  opa.push_back(x);
  strftime (buffer,80,"%m",timeinfo);
  x = buffer;
  opa.push_back(x);
  strftime (buffer,80,"%d",timeinfo);
  x = buffer;
  opa.push_back(x);
  for (auto j = listaContas.begin(); j != listaContas.end(); j++) {
    double pirocao = 0;
    for(auto a = j->movimentacoes.begin(); a!= j->movimentacoes.end();a++){
      if(a->debitoCredito == 'D'){
        int days = rdn(stoi(a->dataMov[0]),stoi(a->dataMov[1]),stoi(a->dataMov[2])) - rdn(stoi(opa[0]), stoi(opa[1]) , stoi(opa[2]));
        if(days <=7){
          pirocao += a->valor;
        }
      }
    }
    pirocao *= 0.0038;
    j->debitar(pirocao,"CPMF");
  }
}

list <Cliente> Banco::get_clientes(){
  for (auto j = listaClientes.begin(); j != listaClientes.end(); j++) {
    cout << "cliente  " << j->nomeCliente <<endl;
  }
}
list <Conta> Banco::get_contas(){
  for (auto j = listaContas.begin(); j != listaContas.end(); j++) {
    cout << "conta  " << j->numConta <<endl;
  }
}
