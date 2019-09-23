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

};

#endif //CONTA_H
