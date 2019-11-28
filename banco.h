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
	list<Conta> listaContas;
	list<Contacorrente> listaContasCorrente;
	list<Contapoupanca> listaContasPoupanca;
	friend class Cliente;
	friend class Conta;
	friend class Movimentacao;
	friend class Interface;


	public:
	Banco(string nomeBanco);
	void setCliente(Cliente c);
	void setConta(Conta c);
	void setConta(Contacorrente c);
	void setConta(Contapoupanca c);
	void deposito(int nconta, double valor);
	void saque(int nconta, double valor);
	void saque(int nconta, double valor, string ano, string mes, string dia);
	void transferencia_conta(int conta_origem, int conta_destino,double valor);
	void tarifa();
	void debitar_cpmf();
	void saldo(int nconta);
	void criar_conta(Cliente c);
	void excluir_cliente(string c);
	void excluir_conta(int nconta);
	list <Cliente> get_clientes();
	list <Conta> get_contas();
	list <Contacorrente> get_contascorrente();
	void gravar_dados();
	void ler_dados();
	void extrato(int nconta, vector<string> di);
	void extrato(int nconta, vector<string> di, vector<string> df);
	string get_nome_banco();
};

#endif //BANCO_H
