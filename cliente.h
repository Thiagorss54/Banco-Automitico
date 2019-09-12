#include <iostream>
#include <string>

#IFNDEF CLIENTE_H
#DEFINE CLIENTE_H

class Cliente{
	private:
	string nomeCliente;
	string cpf_cnpj;
	string endereco;
	string fone;

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
}

#endif