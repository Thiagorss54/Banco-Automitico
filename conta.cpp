#include <iostream>
#include <list>
#include <string>
#include <ctime>
#include "movimentacao.h"
#include "conta.h"
#include "cliente.h"
#include "movimentacao.h"
using namespace std;

void Conta::print(){
		cout << "numero = " << numConta << endl;
		cout << "cliente:" << endl;
		cliente->print();
		cout << "saldo = " << saldo << endl;
		cout << "movimentacao tamanho: ";
		cout << movimentacoes.size()<< endl;
}

int Conta::proximoNumConta = 0;

// void Conta::debitar(float valor_debitado,string descricao,char deb_cred){
// 	Movimentacao *x = new Movimentacao(descricao,deb_cred,valor_debitado);
// 	int aux_saldo = saldo - valor_debitado;
	// if(aux_saldo < 0){
	// 	cout<< "saldo insuficiente" << endl;
	// }
	// else{
	// 	saldo = aux_saldo;
	// }

//}
void Conta::debitar(double v, string d){
	if(saldo - v >= 0){
		Movimentacao mov(d,'D',v);
		saldo -= v;
		movimentacoes.push_back(mov);
		for(auto i=movimentacoes.begin();i!=movimentacoes.end();i++){
			cout << "mov descricao :  "<< i->descricao << endl;
		}
	}
	else{cout << "Saldo insuficiente" << endl;}
}

void Conta::creditar(double v, string d){
	Movimentacao mov(d,'C',v);
	saldo += v;
	movimentacoes.push_back(mov);
	for(auto i=movimentacoes.begin();i!=movimentacoes.end();i++){
		cout << "mov descricao :  "<< i->descricao << endl;
	}
}



// Conta::Conta(){}
Conta::Conta(Cliente *c){
	saldo = 0.0;
	cliente = c;
	proximoNumConta++;
	numConta = proximoNumConta;
}
int Conta::getNumConta(){ return numConta; }
double Conta::getSaldo(){ return saldo; }
Cliente* Conta::getCliente(){ return cliente; }
//list<Movimentacao> Conta::getMovimentacoes(){ return movimentacoes;}



list<Movimentacao> Conta::extrato(){
	if (!movimentacoes.empty()) {
		time_t rawtime;
		string a, m;
		struct tm* timeinfo;
		char buffer[80];
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(buffer, 80, "%Y", timeinfo);
		a = buffer;
		strftime(buffer, 80, "%m", timeinfo);
		m = buffer;
		list<Movimentacao> res;
		for (list<Movimentacao>::iterator it = movimentacoes.begin(); it != movimentacoes.end(); it++) {
			if (it->dataMov[0] == a  && it->dataMov[1] == m) {
				res.push_back(*it);
			}
		}
		if (!res.empty()) {
			return res;
		}
		else {
			cout << "O extrato esta vazio para o mes corrente." << endl;
		}
	}
	else { cout << "A conta nao tem movimentacoes." ;}
}

/*list<Movimentacao> Conta::extrato(vector<string> di){
	if (!movimentacoes.empty()) {
		list<Movimentacao> res;
		for (list<Movimentacao>::iterator it = movimentacoes.begin(); it != movimentacoes.end(); it++) {
			if (it->dataMov[0] >= di[0] && it->dataMov[1] >= di[1] && it->dataMov[2] >= di[2]) {
				res.push_back(*it);
			}
		}
		if (!res.empty()) {
			return res;
		}
		else {
			cout << "O extrato esta vazio a partir da data selecionada." << endl;
		}
	}
	else { cout << "A conta nao tem movimentacoes." ;}
}

list<Movimentacao> Conta::extrato(vector<string> di, vector<string> df){
	if(!movimentacoes.empty()){
		list<Movimentacao> res;
		for(list<Movimentacao>::iterator it = movimentacoes.begin(); it != movimentacoes.end(); it++){
			if (it->dataMov[0] >= di[0] && it->dataMov[1] >= di[1] && it->dataMov[2] >= di[2] && it->dataMov[0] <= df[0] && it->dataMov[1] <= di[1] && it->dataMov[2] <= di[2]){
				res.push_back(*it);
			}
		}
		if (!res.empty()) {
			return res;
		}
		else {
			cout << "O extrato esta vazio para a data selecionada." << endl;
		}
	}
	else { cout << "A conta nao tem movimentacoes."; }
}
*/



Conta::~Conta(){}
