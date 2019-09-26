#include <iostream>
#include <list>
#include <string>
#include <ctime>

#include "conta.h"
#include "cliente.h"
#include "movimentacao.h"
using namespace std;

/*class Conta{
	private:
	int numConta;
	double saldo;
	Cliente cliente;
	list movimentacoes;
	int static proximoNumConta;
*/

Conta::Conta(Cliente c){
	saldo = 0.0;
	cliente = c;
}
int Conta::getNumConta(){ return numConta; }
double Conta::getSaldo(){ return saldo; }
Cliente Conta::getCliente(){ return cliente; }
list<Movimentacao> Conta::getMovimentacoes(){ return movimentacoes;}

void Conta::debitar(double v, string d){
	if(saldo - v > 0){
		Movimentacao mov(d,'D',v);
		saldo -= v;
		movimentacoes.push_back(mov);
	}
	else{cout << "Saldo insuficiente" << endl;}
}

void Conta::creditar(double v, string d){
	Movimentacao mov(d,'D',v);
	saldo += v;
	movimentacoes.push_back(mov);
}

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
			cout << "O extrato est� vazio para o m�s corrente." << endl;
		}
	}
	else { cout << "A conta nao tem movimentacoes." ;}
}

list<Movimentacao> Conta::extrato(vector<string> di){
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
			cout << "O extrato est� vazio a partir da data selecionada." << endl;
		}
	}
	else { cout << "A conta n�o tem movimentacoes." ;}
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
			cout << "O extrato est� vazio para a data selecionada." << endl;
		}
	}
	else { cout << "A conta n�o tem movimentacoes."; }
}
