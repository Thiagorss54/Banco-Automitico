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

//jfisjvi

Conta::Conta(Cliente c){
	saldo = 0;
	cliente = c;
}
int Conta::getNumConta(){ return numConta; }
double Conta::getSaldo(){ return saldo; }
Cliente Conta::getCliente(){ return cliente; }
list<Movimentacao> Conta::getMovimentacoes(){ return movimentacoes;}

void Conta::debitar(double v, string d){
	if(saldo - v > 0){
		Movimentacao mov(d,"D",v);
		saldo -= v;
		movimentacoes.push_back(mov);
	}
	else{cout << "Saldo insuficiente" << endl;}
}

void Conta::creditar(double v, string d){
	Movimentacao mov(d,"D",v);
	saldo += v;
	movimentacoes.push_back(mov);
}

list<Movimentacao> extrato(){
	time_t rawtime;
	string a;
	struct tm * timeinfo;
	char buffer [80];
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime (buffer,80,"%m",timeinfo);
	a = buffer;



}

list<Movimentacao> extrato(vector<string> di);
list<Movimentacao> extrato(vector<string> di, vector<string> df){
	if(!movimentacoes.empty()){
		for(list<Movimentacao>::iterator it = movimentacoes.begin(); it != movimentacoes.end(); it++){
			
		}
	}
}
