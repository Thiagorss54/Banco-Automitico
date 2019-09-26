#ifndef CONTA_H
#define CONTA_H
#include <iostream>
#include <list>
#include <string>
#include "movimentacao.h"
#include "cliente.h"

using std::list;
using std::string;

class Conta{
	private:
	int numConta;
	double saldo;
	Cliente cliente;
	list<Movimentacao> movimentacoes; 
	int static proximoNumConta;
	friend class Cliente;
	friend class Movimentacao;

	public:
	
	Conta(Cliente c);
	int getNumConta();
	double getSaldo();
	Cliente getCliente();
	list<Movimentacao> getMovimentacoes();
	void debitar(double v, string d);
	void creditar(double v, string d);
	list<Movimentacao> extrato();
	list<Movimentacao> extrato(vector<string> di);
	list<Movimentacao> extrato(vector<string> di, vector<string> df);

};

#endif //CONTA_H
