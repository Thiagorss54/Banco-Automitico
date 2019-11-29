#ifndef BANCO_H
#define BANCO_H

#include <iostream>
#include <list>
#include <string>
#include <map>

#include "cliente.h"
#include "conta.h"
#include "movimentacao.h"
#include "contacorrente.h"
#include "contapoupanca.h"

using namespace std;

class Banco{
	private:
	string nomeBanco;
	list<Cliente> listaClientes;
	
	list<Contacorrente> listaContasCorrente;
	list<Contapoupanca> listaContasPoupanca;
	friend class Cliente;
	friend class Conta;
	friend class Movimentacao;
	friend class Interface;


	public:
	Banco(string nomeBanco);
	void setCliente(Cliente c);//ok
	
	void setConta(Contacorrente c);//ok
	void setConta(Contapoupanca c);//ok

	void deposito(int nconta, double valor);//ok
	void saque(int nconta, double valor);//ok
	void saque(int nconta, double valor, string ano, string mes, string dia);
	void transferencia_conta(int conta_origem, int conta_destino,double valor);//ok
	void tarifa();//ok
	void debitar_cpmf();//ok
	void saldo(int nconta);//ok
	//void criar_conta(Cliente c);
	void criar_conta_corrente(Cliente c);//ok
	void criar_conta_poupanca(Cliente c);//ok
	void excluir_cliente(string c);//ok
	void excluir_conta(int nconta);//ok
	list <Cliente> get_clientes();//ok
	list <Contacorrente> get_contascorrente();//ok
	list <Contapoupanca> get_contaspoupanca();//ok
	void gravar_dados();																		
	void ler_dados();
	void extrato(int nconta, vector<string> di);
	void extrato(int nconta, vector<string> di, vector<string> df);
	string get_nome_banco();
};

#endif //BANCO_H
