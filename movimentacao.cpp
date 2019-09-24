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

string Movimentacao::getDataMov(){ return dataMov; }
string Movimentacao::getDescricao(){ return descricao; }
char Movimentacao::getOp(){ return debitoCredito; }
double Movimentacao::getValor(){ return valor; }