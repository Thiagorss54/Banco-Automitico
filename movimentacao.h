#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using std::string;
using std::vector;

class Movimentacao{
	private:
	vector<string> dataMov;
	string descricao;
	char debitoCredito;
	double valor;
	friend class Conta;

	public:
	Movimentacao(string d, char op, double v);
	vector<string> getDataMov();
	string getDescricao();
	char getOp();
	double getValor();
};

#endif //MOVIMENTACAO_H
