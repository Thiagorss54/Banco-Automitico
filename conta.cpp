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

Conta(Cliente c){
	saldo = 0;
	cliente = c;
}
int getNumConta(){ return numConta; }
double getSaldo(){ return saldo; }
Cliente getCliente(){ return cliente; }
list getMovimentacoes(){ return movimentacoes; }
void debitar(string d, double v){
	if(saldo - v > 0){
		movimentacao mov(d,"D",v);
		saldo -= v;
	}
	else{cout << "Saldo insuficiente" << endl;}
	
}

#endif