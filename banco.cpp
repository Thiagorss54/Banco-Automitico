#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "conta.h"
#include "cliente.h"
#include "movimentacao.h"
#include "banco.h"


Banco::Banco(string nBanco){
  nomeBanco = nBanco;
}

void Banco::setcliente(Cliente c){
  cliente.push_back(c);
}


void Banco::setconta(Conta c){
  contas.push_back(c);
}

void Banco::operator =(const Banco& c){
  this->nomeBanco = c.nomeBanco;
  this->cliente = c.cliente;
  this->contas = c.contas;
  this->ControleClienteConta = c.ControleClienteConta;

}
