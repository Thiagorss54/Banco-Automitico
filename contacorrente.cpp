#include "contacorrente.h"

bool Contacorrente::debitar(double v, string d){
	if((saldo + limitecredito_) - v >= 0){
		Movimentacao mov(d,'D',v);
		saldo -= v;
		movimentacoes.push_back(mov);
		for(auto i=movimentacoes.begin();i!=movimentacoes.end();i++){
			i->print();
		}
		return true;
	}
	else{
		cout << "Saldo insuficiente" << endl;
		return false;
	}
}
bool Contacorrente::debitar(double v,Movimentacao mov){
	if((saldo + limitecredito_) - v >= 0){
		saldo -= v;
		movimentacoes.push_back(mov);
		// for(auto i=movimentacoes.begin();i!=movimentacoes.end();i++){
		// 	cout << "mov descricao :  "<< i->descricao << endl;
		// }
		return true;
	}
	else{
		cout << "Saldo insuficiente" << endl;
		return false;
	}
}

Contacorrente::~Contacorrente()
{
}
