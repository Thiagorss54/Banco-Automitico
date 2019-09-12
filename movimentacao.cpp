#include <iostream>
#include <string>
#include <ctime> 

#include "movimentacao.h"

Movimentacao::Movimentacao(string d, char op, double v){
	time_t rawtime;
	string dat = ctime(&rawtime);
	dataMov = dat;
	descricao = d;
	debitoCredito = op;
	valor = v;
}

string Movimentacao::getDataMov{ return dataMov; }
string Movimentacao::getDescricao{ return descricao; }
char Movimentacao::getOp{ return debitoCredito; }
double Movimentacao::getValor{ return valor; }