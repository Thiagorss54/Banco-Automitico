#include <iostream>
#include <list>
#include <string>

#include "conta.h"
#include "cliente.h"
#include "movimentacao.h"

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
Cliente COonta::getCliente(){ return cliente; }
list<movimentacao> Conta::getMovimentacoes(){ return movimentacoes; }
void Conta::debitar(string d, double v){
	if(saldo - v > 0){
		movimentacao mov(d,"D",v);
		saldo -= v;
	}
	else{cout << "Saldo insuficiente" << endl;}
}