#ifndef CONTA_H
#define CONTA_H
#include <iostream>
#include <list>
#include <string>
#include "cliente.h"
#include "movimentacao.h"

using namespace std;

class Conta{
	private:
	int numConta;
	double saldo;
	Cliente *cliente;
	list<Movimentacao> movimentacoes;
	friend class Movimentacao;
	friend class Banco;

	public:
	static int proximoNumConta;
	Conta();
	Conta(Cliente *c);
	int getNumConta();
	double getSaldo();
	Cliente* getCliente();
	~Conta();
	bool debitar(double v,string d);
	bool debitar(double v,Movimentacao mov);
	void creditar(double v, string d);
	void print();
	list<Movimentacao> extrato();
	list<Movimentacao> extrato(vector<string> di);
	list<Movimentacao> extrato(vector<string> di, vector<string> df);
};

#endif //CONTA_H
