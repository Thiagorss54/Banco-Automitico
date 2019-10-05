#ifndef INTERFACE_H
#define INTERFACE_H

#include "movimentacao.h"
#include "conta.h"
#include "cliente.h"
#include "movimentacao.h"
#include "banco.h"

class Interface{
    public:
    Interface();
    void menu();
    void cadastrarCliente();
    void criarConta();
    void excluirCliente();
    void excluirConta();
    void deposito();
    void saque();
    void transferencia();
    void cobrarTarifa();
    void cobrarCPMF();
    void saldo();
    void extrato();
    void listarClientes();
    void listarContas();
    void main() ;
    
    private:
        Banco banco(string x);




};


#endif //INTERFACE_H