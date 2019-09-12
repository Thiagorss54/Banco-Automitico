#include <iostream>
#include <string>

#IFNDEF MOVIMENTACAO_H
#DEFINE MOVIMENTACAO_H

class Movimentacao{
	private:
	string dataMov;
	string descricao;
	char debidoCredito;
	double valor;	
	
	public:
	Movimentacao(string d, char op, double v);
	string getDataMov();
	string getDescricao();
	char getOp();
	double getValor();
}

#endif
