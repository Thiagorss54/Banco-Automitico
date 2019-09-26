#ifndef BANCO_H
#define BANCO_H

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "cliente.h"
#include "conta.h"

using namespace std;

class Banco{
	private:
	string nomeBanco;
	std::vector<Cliente> cliente;//Por que ñ usar map???
	std::vector<Conta> contas;

	public:
	Banco(string nomeBanco);
	void setcliente(Cliente c);
	void setconta(Conta c);


};

#endif //BANCO_H
