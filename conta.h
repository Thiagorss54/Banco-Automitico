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
	Movimentacao *movimentacao;
	public:
	static int proximoNumConta;
	Conta();
	Conta(Cliente *c);
	int getNumConta();
	double getSaldo();
	Cliente* getCliente();
	~Conta();
	void debitar(float valor_debitado,string descricao,char deb_cred);
	void print();
};

#endif //CONTA_H
