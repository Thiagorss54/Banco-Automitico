#include <iostream>
#include <list>
#include <string>
#include <ctime>
#include "movimentacao.h"
#include "conta.h"
#include "cliente.h"
#include "movimentacao.h"
using namespace std;

// void Conta::print(){
// 		cout << "\t\t\t  CLIENTE" << cont << endl;
// 		cout << "numero = " << numConta << endl;
// 		cout << "cliente:" << endl;
// 		cliente.print();
// 		cout << "saldo = " << saldo << endl;

// }

int Conta::proximoNumConta = 0;

bool Conta::debitar(double v, string d){
	if(saldo - v >= 0){
		Movimentacao mov(d,'D',v);
		saldo -= v;
		movimentacoes.push_back(mov);
		// for(auto i=movimentacoes.begin();i!=movimentacoes.end();i++){
		// 	i->print();
		// }
		return true;
	}
	else{
		cout << "Saldo insuficiente" << endl;
		return false;
	}
}

bool Conta::debitar(double v,Movimentacao mov){
	if(saldo - v >= 0){
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



void Conta::creditar(double v, string d){
	Movimentacao mov(d,'C',v);
	saldo += v;
	movimentacoes.push_back(mov);
	// for(auto i=movimentacoes.begin();i!=movimentacoes.end();i++){
	// 	 cout << "mov descricao :  "<< i->descricao << endl;
	// }
}

Conta::Conta(Cliente c){
	saldo = 0.0;
	cliente = c;
	proximoNumConta++;
	numConta = proximoNumConta;
}

Conta::Conta(int nconta, double sald, Cliente c, list<Movimentacao> mov){
	numConta = nconta;
	saldo = sald;
	cliente = c;
	for (list<Movimentacao>::iterator it = mov.begin(); it != mov.end(); it++) {
			movimentacoes.push_back(*it);
	}
	if (nconta >= proximoNumConta){
		proximoNumConta = nconta+1;
	}
}

int Conta::getNumConta(){ return numConta; }
double Conta::getSaldo(){ return saldo; }
Cliente Conta::getCliente(){ return cliente; }
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

list<Movimentacao> Conta::extrato(vector<string> di){
	list<Movimentacao> res;
	if (!movimentacoes.empty()) {
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
			return res;
		}
	}
	else {
		cout << "A conta nao tem movimentacoes." ;
		return res;
	}
}
///////////////////////////////Se o ano e o mes forem difernetes da erro na validaçao dos dias
/*list<Movimentacao> Conta::extrato(vector<string> di, vector<string> df){
	list<Movimentacao> res;
	if(!movimentacoes.empty()){
		for(list<Movimentacao>::iterator it = movimentacoes.begin(); it != movimentacoes.end(); it++){
			cout << "dataMov0 " << it->dataMov[0]<<"  dataMov1 " << it->dataMov[1]<< "   dataMov2 " << it->dataMov[2]<<endl;
			// if (it->dataMov[0] >= di[0] && it->dataMov[1] >= di[1] && it->dataMov[2] >= di[2] && it->dataMov[0] <= df[0]
			// 	&& it->dataMov[1] <= di[1] && it->dataMov[2] <= di[2]){
			if(it->dataMov[0] >= di[0] && it->dataMov[0] <= df[0]){

				if(di[0]==df[0] && it->dataMov[1] >= di[1] && it->dataMov[1] <= df[1]){

						if((di[1]==df[1]) && (it->dataMov[2] >= di[2] && it->dataMov[2] <= df[2])){
							cout << "valor:: "<< it->valor << endl ;
							res.push_back(*it);
						}
						else if(di[1]<df[1]){

						}
					}
				}
			}


		if (!res.empty()) {
			return res;
		}
		else {
			cout << "O extrato esta vazio a partir da data selecionada." << endl;
			return res;
		}
	}
	else {
		cout << "A conta nao tem movimentacoes." ;
		return res;
	}
}
*/

/////////////////////////Extrato B
list<Movimentacao> Conta::extrato(vector<string> di, vector<string> df){
	list<Movimentacao> res;
	string diadehoje;
	auto aux1 = di[0] + di[1] + di[2];
	auto aux2 = df[0] + df[1] + df[2];
	cout <<"Di  " << aux1<< "   Df  "  << aux2 << endl;

	if(!movimentacoes.empty()){
		for(list<Movimentacao>::iterator it = movimentacoes.begin(); it != movimentacoes.end(); it++){

			auto dataMovimentacao = it->dataMov[0] + it->dataMov[1] + it->dataMov[2];
			// cout << "dataMovimentacao " << dataMovimentacao << endl;
			if(dataMovimentacao >= aux1 && dataMovimentacao <= aux2 ){
				// cout << "primiu   " << dataMovimentacao << endl;
				res.push_back(*it);
			}
		}
		if (!res.empty()) {
			return res;
		}
		else {
			cout << "O extrato esta vazio a partir da data selecionada." << endl;
			return res;
		}
	}
	else {
		cout << "A conta nao tem movimentacoes." ;
		return res;
	}
}
