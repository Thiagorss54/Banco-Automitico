#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
using namespace std;

class Cliente{
	private:
	string nomeCliente;
	string cpf_cnpj;
	string endereco;
	string fone;

	friend class Banco;
	friend class Conta;
	friend class Movimentacao;
	friend class Interface;

	public:
		Cliente();
		Cliente(string n, string c, string e, string f);
		void operator =(const Cliente& c);
		bool operator ==(const Cliente& c);
		string getNome();
		string getCpf_cnpj();
		string getEndereco();
		string getFone();
		void setNome(string n);
		void setCpf_cnpj(string c);
		void setEndereco(string e);
		void setFone(string f);
		~Cliente();
		void print();
};

#endif //CLIENTE_H
