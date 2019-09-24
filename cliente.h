#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
using std::string;

class Cliente{
	private:
	string nomeCliente;
	string cpf_cnpj;
	string endereco;
	string fone;
	//gabriel gay

	public:
	Cliente(string n, string c, string e, string f);
	string getNome();
	string getCpf_cnpj();
	string getEndereco();
	string getFone();
	void setNome(string n);
	void setCpf_cnpj(string c);
	void setEndereco(string e);
	void setFone(string f);
};

#endif //CLIENTE_H
