#ifndef BANCO_H
#define BANCO_H

#include <iostream>
#include <list>
#include <string>
#include <map>

#include "cliente.h"
#include "conta.h"
#include "movimentacao.h"

using namespace std;

class Banco{
	private:
	string nomeBanco;
	list<Cliente> listaClientes;
	list<Conta> listaContas;
	friend class Cliente;
	friend class Conta;
	friend class Movimentacao;

	public:
	Banco(string nomeBanco);
	void setCliente(Cliente c);
	void setConta(Conta c);
	void operator =(const Banco& c);
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
	void gravar_dados();
	void ler_dados();
};

#endif //BANCO_H
