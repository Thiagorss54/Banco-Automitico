#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "movimentacao.h"
using namespace std;

Movimentacao::Movimentacao(string d, char op, double v){
	time_t rawtime;
	string a;
	struct tm * timeinfo;
	char buffer [80];
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime (buffer,80,"%Y",timeinfo);
	a = buffer;
	dataMov.push_back(a);
	strftime (buffer,80,"%m",timeinfo);
	a = buffer;
	dataMov.push_back(a);
	strftime (buffer,80,"%d",timeinfo);
	a = buffer;
	dataMov.push_back(a);

	this->descricao = d;
	this->debitoCredito = op;
	this->valor = v;
	cout<<"descricao = "<< this->descricao <<endl;
	cout<< "deb ou cred = " << this->debitoCredito << endl;
	cout <<"valor = " << this->valor << endl;
}

Movimentacao::Movimentacao(string d, char op, double v, string ano, string mes, string dia){
	dataMov.push_back(ano);
	dataMov.push_back(mes);
	dataMov.push_back(dia);

	this->descricao = d;
	this->debitoCredito = op;
	this->valor = v;
	cout<<"descricao = "<< this->descricao <<endl;
	cout<< "deb ou cred = " << this->debitoCredito << endl;
	cout <<"valor = " << this->valor << endl;
}
void Movimentacao::print(){
	cout<<"descricao = "<< this->descricao <<endl;
	cout<< "deb ou cred = " << this->debitoCredito << endl;
	cout <<"valor = " << this->valor << endl;
}

vector<string> Movimentacao::getDataMov(){ return dataMov; }
string Movimentacao::getDescricao(){ return descricao; }
char Movimentacao::getOp(){ return debitoCredito; }
double Movimentacao::getValor(){ return valor; }
