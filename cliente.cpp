#include <iostream>
#include <string>
#include "cliente.h"
using namespace std;

Cliente::Cliente(){};
Cliente::Cliente(string n, string c, string e, string f){
	nomeCliente = n;
	cpf_cnpj = c;
	endereco = e;
	fone = f;
}
string Cliente::getNome(){ return nomeCliente; }
string Cliente::getCpf_cnpj(){ return cpf_cnpj; }
string Cliente::getEndereco(){ return endereco; }
string Cliente::getFone(){ return fone; }

void Cliente::setNome(string n){ nomeCliente = n; }
void Cliente::setCpf_cnpj(string c){ cpf_cnpj = c; }
void Cliente::setEndereco(string e){ endereco = e; }
void Cliente::setFone(string f){ fone = f; }
void Cliente::operator =(const Cliente& c){
	this->nomeCliente = c.nomeCliente;
	this->cpf_cnpj = c.cpf_cnpj;
	this->endereco = c.endereco;
	this->fone = c.fone;
}

bool Cliente::operator ==(const Cliente& c){
	if((this->nomeCliente == c.nomeCliente) && (this->cpf_cnpj == c.cpf_cnpj) && 
	(this->endereco == c.endereco) && (this->fone == c.fone)){
		return true;
	}
	else return false;
}
Cliente::~Cliente(){}
void Cliente::print(){
	cout<<"nome = "<< nomeCliente <<endl;
	cout<< "cpf = " << cpf_cnpj << endl;
	cout <<"endereco = " << endereco << endl;
	cout << "telefone = " << fone << endl;
}
