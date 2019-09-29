#ifndef CONTA_H
#define CONTA_H
#include <iostream>
#include <list>
#include <string>
#include "cliente.h"

using namespace std;

class Conta{
	private:
	int numConta;
	double saldo;
	Cliente *cliente;	

	public:
	static int proximoNumConta;

	Conta(Cliente *c);
	int getNumConta();
	double getSaldo();
	Cliente* getCliente();
	~Conta();
	void print();
};

#endif //CONTA_H
