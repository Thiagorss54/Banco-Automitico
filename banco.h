#ifndef BANCO_H
#define BANCO_H

#include <iostream>
#include <list>
#include <string>
#include <map>

#include "cliente.h"
#include "conta.h"

using namespace std;

class Banco{
	private:
	string nomeBanco;
	list<Cliente> cliente;//Por que ñ usar map???
	list<Conta> contas;
	map < Cliente, Conta > ControleClienteConta;

	public:
	Banco(string nomeBanco);
	void setcliente(Cliente c);
	void setconta(Conta c);


};

#endif //BANCO_H
