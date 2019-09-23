#include <iostream>
#include <list>
#include <string>

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

