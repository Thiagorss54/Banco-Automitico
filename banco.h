#ifndef BANCO_H
#define BANCO_H

#include <iostream>
#include <list>
#include <string>
#include <map>

#include "cliente.h"
#include "conta.h"
#include "movimentacao.h"

using namespace std;

class Banco{
	private:
	string nomeBanco;
	list<Cliente> listaCliente;
	list<Conta> listaContas;
	friend class Cliente;
	friend class Conta;

	public:
	Banco(string nomeBanco);
	void setCliente(Cliente c);
	void setConta(Conta c);
	void operator =(const Banco& c);
	void delCliente(int num);
	void delConta(int num);

};

#endif //BANCO_H
