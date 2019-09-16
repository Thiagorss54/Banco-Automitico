#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "conta.h"
#include "cliente.h"
#include "movimentacao.h"


Banco::Banco(string nBanco){
  nomeBanco = nBanco;
}

void Banco::setcliente(Cliente c){
  cliente.push_back(c);
}
void Banco::setconta(Conta c){
  contas.push_back(c);
}
