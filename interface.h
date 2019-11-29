#ifndef INTERFACE_H
#define INTERFACE_H

#include "movimentacao.h"
#include "conta.h"
#include "cliente.h"
#include "movimentacao.h"
#include "banco.h"

class Interface{
    public:
    Interface(string nomeBanco);
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
        string nomeBanco_;
        Banco* NU;
       




};


#endif //INTERFACE_H