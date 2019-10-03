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
  for (auito j = listaContas.begin(); j != listaContas.end(); j++) {
    if(nconta == j->numConta){
      j->saldo += valor;
    }
}
