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

	descricao = d;
	debitoCredito = op;
	valor = v;
}
void Movimentacao::print(){
	cout<<"descricao = "<< descricao <<endl;
	cout<< "deb ou cred = " << debitoCredito << endl;
	cout <<"valor = " << valor << endl;
}

vector<string> Movimentacao::getDataMov(){ return dataMov; }
string Movimentacao::getDescricao(){ return descricao; }
char Movimentacao::getOp(){ return debitoCredito; }
double Movimentacao::getValor(){ return valor; }

void Movimentacao::setDescricao(string descr){
	descricao =  descr;
}

void Movimentacao::setOp(char db){
	debitoCredito = db;
}

void Movimentacao::setValor(double v){
	valor = v;
}


