#ifndef INTERFACE_H
#define INTERFACE_H

#include "movimentacao.h"
#include "conta.h"
#include "cliente.h"
#include "movimentacao.h"
#include "banco.h"

class Interface{
    public:
    void menu();
    void cadastrarCliente();
    void criarConta();
    void excluirCliente();
    void excluirConta();
    void deposito();
    void saque();
    void tranferencia();
    void cobrarTarifa();
    void cobrarCPMF();
    void saldo();
    void extrato();
    void listarClientes();
    void listarContas();
    void main() ;
    




};


#endif //INTERFACE_H