#include <iostream>
#include <list>
#include <string>
#include <vector>

#IFNDEF BANCO_H
#DEFINE BANCO_H

class Banco{
	private:
	string nomeBanco;
	std::vector<Cliente> cliente;//Por que ñ usar map???
	std::vector<Conta> contas;

	public:
	Banco(string nomeBanco);
	void setcliente(Cliente c);
	void setconta(Conta c);


}

#endif
