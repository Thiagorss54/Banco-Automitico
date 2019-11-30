#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <fstream>
#include "conta.h"
#include "cliente.h"
#include "movimentacao.h"
#include "banco.h"

using namespace std;

Banco::Banco(string nBanco){
  nomeBanco = nBanco;
} 

void Banco::setCliente(Cliente c) {
	listaClientes.push_back(c);
}


void Banco::setConta(Contacorrente c){
	listaContasCorrente.push_back(c);
}
void Banco::setConta(Contapoupanca c){
  listaContasPoupanca.push_back(c);
}


void Banco::criar_conta_corrente(Cliente c){
  Contacorrente a(c,100);
  this->setConta(a);
}
void Banco::criar_conta_poupanca(Cliente c){
  Contapoupanca a(c);
  this->setConta(a);
}

void Banco::excluir_cliente(string c){
  int aux = 0;
  Cliente a;
  for (auto i = listaClientes.begin() ; i != listaClientes.end()++ ; i++){
    if (c == i->cpf_cnpj){
      for (auto j = listaContasCorrente.begin();j!=listaContasCorrente.end()++;j++){
        if (i->nomeCliente == j->cliente.getNome()){
          aux++;
        }
      }
      for (auto j = listaContasPoupanca.begin();j!=listaContasPoupanca.end()++;j++){
        if (i->nomeCliente == j->cliente.getNome()){
          aux++;
        }
      }
      if(aux == 0){
        a = *i;
      }
    }
  }
  if(aux == 0){
    listaClientes.remove(a);
  }
  else{
    cout<<"Cliente ainda possui conta"<<endl;
  }
}

void Banco::excluir_conta(int nconta){
  int aux=0;
  double sald;
  Cliente c;
  list<Movimentacao> mov;
  int contador=0; //teste
  for (list<Contacorrente>::iterator it = listaContasCorrente.begin(); it != listaContasCorrente.end(); ++it) {
    if(nconta == it->numConta){
      listaContasCorrente.erase(it);
      aux++;
      break;
    }
  }
  for (list<Contapoupanca>::iterator it = listaContasPoupanca.begin(); it != listaContasPoupanca.end(); it++) {
    if(nconta == it->numConta){
      listaContasPoupanca.erase(it);
      aux++;
      break;
    }
  }
  if(aux == 0){
    cout<<"Conta nao existe no banco de dados."<<endl;
  }
}

void Banco::deposito(int nconta, double valor){
   for (auto j = listaContasPoupanca.begin();j!=listaContasPoupanca.end()++;j++) {
    if(nconta == j->numConta){
      j->creditar(valor, "Deposito");
    }
  }
  for (auto j = listaContasCorrente.begin();j!=listaContasCorrente.end()++;j++){
    if(nconta == j->numConta){
      j->creditar(valor, "Deposito");
    }
  }
}

void Banco::saque(int nconta, double valor){
  for (auto j = listaContasPoupanca.begin();j!=listaContasPoupanca.end()++;j++) {
    if(nconta == j->numConta){
      j->debitar(valor, "Saque");
    }
  }
  for (auto j = listaContasCorrente.begin();j!=listaContasCorrente.end()++;j++) {
    if(nconta == j->numConta){
      j->debitar(valor, "Saque");
    }
  }
}

void Banco::saque(int nconta, double valor, string ano, string mes, string dia){
  Movimentacao mov("Saque",'D',valor,ano,mes,dia);
   for (auto j = listaContasCorrente.begin();j!=listaContasCorrente.end()++;j++) {
    if(nconta == j->numConta){
      j->debitar(valor,mov);
    }
  }
  for (auto j = listaContasPoupanca.begin();j!=listaContasPoupanca.end()++;j++) {
    if(nconta == j->numConta){
      j->debitar(valor,mov);
    }
  }
}

void Banco::transferencia_conta(int conta_origem, int conta_destino,double valor){
  int aux=0;
  for (auto j = listaContasPoupanca.begin(); j != listaContasPoupanca.end(); j++) {
    if(conta_origem == j->numConta){
      if(j->debitar(valor,"Transferencia para a conta " + to_string(conta_destino))){
        for (auto k = listaContasPoupanca.begin(); k != listaContasPoupanca.end(); k++) {
          if(conta_destino == k->numConta){
            k->creditar(valor, "Transferencia da conta " + to_string(conta_origem));
             aux++;
          }
        }
        for (auto k = listaContasCorrente.begin(); k != listaContasCorrente.end(); k++) {
          if(conta_destino == k->numConta){
            k->creditar(valor, "Transferencia da conta " + to_string(conta_origem));
            aux++;
          }
        }
      }
    }
  }

  for (auto j = listaContasCorrente.begin(); j != listaContasCorrente.end(); j++) {
    if(conta_origem == j->numConta){
      if(j->debitar(valor,"Transferencia para a conta " + to_string(conta_destino))){
        for (auto k = listaContasPoupanca.begin(); k != listaContasPoupanca.end(); k++) {
          if(conta_destino == k->numConta){
            k->creditar(valor, "Transferencia da conta " + to_string(conta_origem));
            aux++;
          }
        }
        for (auto k = listaContasCorrente.begin(); k != listaContasCorrente.end(); k++) {
          if(conta_destino == k->numConta){
            k->creditar(valor, "Transferencia da conta " + to_string(conta_origem));
            aux++;
          }
        }
      }
    }
  }
  if(aux == 0){
    cout<<"Não foi possível realizar a transacao"  <<endl;
  }
}

void Banco::tarifa(){
  for (auto j = listaContasCorrente.begin(); j != listaContasCorrente.end(); j++) {
    j->debitar(15, "Cobranca de Tarifa");
  }
}

int rdn(int y, int m, int d) { /* Rata Die day one is 0001-01-01 */
  if (m < 3)
  y--, m += 12;
  return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}

void Banco::debitar_cpmf(){
  vector<string> opa ;
  time_t rawtime;
  string x;
  struct tm * timeinfo;
  char buffer [80];
  time (&rawtime);
  timeinfo = localtime (&rawtime);
  strftime (buffer,80,"%Y",timeinfo);
  x = buffer;
  opa.push_back(x);
  strftime (buffer,80,"%m",timeinfo);
  x = buffer;
  opa.push_back(x);
  strftime (buffer,80,"%d",timeinfo);
  x = buffer;
  opa.push_back(x);
  for (auto j = listaContasCorrente.begin(); j != listaContasCorrente.end(); j++) {
    double aux1 = 0;
    for(auto a = j->movimentacoes.begin(); a!= j->movimentacoes.end();a++){
      if(a->debitoCredito == 'D'){
        int days = rdn(stoi(a->dataMov[0]),stoi(a->dataMov[1]),stoi(a->dataMov[2])) - rdn(stoi(opa[0]), stoi(opa[1]) , stoi(opa[2]));
        if(days <=7){
          aux1 += a->valor;
        }
      }
    }
    aux1 *= 0.0038;
    j->debitar(aux1,"CPMF");
  }
  for (auto j = listaContasPoupanca.begin(); j != listaContasPoupanca.end(); j++) {
    double aux1 = 0;
    for(auto a = j->movimentacoes.begin(); a!= j->movimentacoes.end();a++){
      if(a->debitoCredito == 'D'){
        int days = rdn(stoi(a->dataMov[0]),stoi(a->dataMov[1]),stoi(a->dataMov[2])) - rdn(stoi(opa[0]), stoi(opa[1]) , stoi(opa[2]));
        if(days <=7){
          aux1 += a->valor;
        }
      }
    }
    aux1 *= 0.0038;
    j->debitar(aux1,"CPMF");
  }
}

void Banco::saldo(int nconta){
  int achou=0;
  for (auto j = listaContasCorrente.begin(); j != listaContasCorrente.end(); j++) {
    if(nconta == j->numConta){
      cout<<"O saldo da conta "<<nconta<<" é  RS"<<j->saldo<<endl;
      achou=1;
    }
  }
  for (auto j = listaContasPoupanca.begin(); j != listaContasPoupanca.end(); j++) {
    if(nconta == j->numConta){
      double saldo = 0;
      achou =1;
      for(int i =0; i < 28;i++){
        saldo+=j->getSaldo(i+1);
      }
      cout<<"O saldo da conta: "<<nconta<<" = "<<saldo<<endl;
    }
  }
  if(achou ==0){
    cout <<"OPERACAO INVALIDA. CONTA INEXISTENTE!"<< endl;
    //system("pause");
  }
}

list <Cliente> Banco::get_clientes(){
  list<Cliente> aux;
  for (auto j = listaClientes.begin(); j != listaClientes.end(); j++) {
    // cout<<"Cliente "<<j->nomeCliente<<endl;
    aux.push_back(*j);
  }
  return aux;
}

list <Contacorrente> Banco::get_contascorrente(){
  list<Contacorrente> aux;
  for (auto j = listaContasCorrente.begin(); j != listaContasCorrente.end(); j++) {
    //cout<<"Conta Corrente "<<j->numConta<<endl;
    aux.push_back(*j);
  }
  return aux;
}

list <Contapoupanca> Banco::get_contaspoupanca(){
  list<Contapoupanca> aux;
  for (auto j = listaContasPoupanca.begin(); j != listaContasPoupanca.end(); j++) {
    //cout<<"Conta Poupanca "<<j->numConta<<endl;
    aux.push_back(*j);
  }
  return aux;
}

void Banco::gravar_dados(){
  ofstream out("Bancodedados.txt");
  out<<"Clientes"<<endl;
  list<Cliente> c = get_clientes();
  for (auto j = c.begin() ; j!= c.end(); j++){
    out<<j->nomeCliente<<endl;
    out<<j->cpf_cnpj<<endl;
    out<<j->endereco<<endl;
    out<<j->fone<<endl;
  }
  list<Contacorrente> cc = get_contascorrente();
  for (auto j = cc.begin() ; j != cc.end() ; j++){
    out<<"ContaCC"<<endl;
    out<<j->numConta<<endl;
    out<<j->saldo<<endl;
    double l = j->lim_cred();
    out<<l<<endl;
    Cliente clienteaux = j->cliente;;
    string stringaux = clienteaux.getNome();
    out<<stringaux<<endl;
    for(auto k = j->movimentacoes.begin(); k != j->movimentacoes.end(); k++){
      out<<"mov"<<endl;
      out<<k->dataMov[0]<<endl;
      out<<k->dataMov[1]<<endl;
      out<<k->dataMov[2]<<endl;
      out<<k->descricao<<endl;
      out<<k->debitoCredito<<endl;
      out<<k->valor<<endl;
    }
  }
  list<Contapoupanca> cp = get_contaspoupanca();
  for (auto j = cp.begin() ; j != cp.end() ; j++){
    out<<"ContaCP"<<endl;
    out<<j->numConta<<endl;
    for(int i =0; i < 28;i++){
      double s = j->getSaldo(i+1);
      out<<s<<endl;
    }
    Cliente clienteaux = j->cliente;;
    string stringaux = clienteaux.getNome();
    out<<stringaux<<endl;
    for(auto k = j->movimentacoes.begin(); k != j->movimentacoes.end(); k++){
      out<<"mov"<<endl;
      out<<k->dataMov[0]<<endl;
      out<<k->dataMov[1]<<endl;
      out<<k->dataMov[2]<<endl;
      out<<k->descricao<<endl;
      out<<k->debitoCredito<<endl;
      out<<k->valor<<endl;
    }
  }
  out.close();
}

void Banco::ler_dados(){
  ifstream in("Bancodedados.txt");
  string linha;
  getline(in,linha);
  while (!(in.eof())) {
    if(linha == "Clientes"){
      getline(in,linha);
      while(linha != "ContaCC"){
        string nome = linha;
        getline(in,linha);
        string cpf = linha;
        getline(in,linha);
        string endereco = linha;
        getline(in,linha);
        string fone = linha;
        Cliente a (nome,cpf,endereco,fone);
        this->setCliente(a);
        getline(in,linha);
      }
    }
    else if(linha == "ContaCC"){
      getline(in,linha);
      int nconta = stoi(linha);
      getline(in,linha);
      double sald = stod(linha);
      getline(in,linha);
      double limcred = stod(linha);
      getline(in,linha);
      string ncli = linha;
      list<Cliente> c = get_clientes();
      Cliente aux;
      for (auto cli = c.begin() ; cli != c.end() ; cli++){
        if(ncli == cli->nomeCliente){
          aux.setNome(cli->nomeCliente);
          aux.setCpf_cnpj(cli->cpf_cnpj);
          aux.setEndereco(cli->endereco);
          aux.setFone(cli->fone);
          break;
        }
      }
      list<Movimentacao> m;
      while(linha != "ContaCC"){
        getline(in,linha);
        if(linha.size() == 0) {break;}
        if(linha == "ContaCP") {break;}
        if(linha == "ContaCC") {break;}
        if(linha=="mov") getline(in,linha);
        while((linha != "mov")){
          string ano = linha;
          getline(in,linha);
          string mes = linha;
          getline(in,linha);
          string dia = linha;
          getline(in,linha);
          string d = linha;
          getline(in,linha);
          char op = linha[0];
          getline(in,linha);
          double v = stod(linha);
          Movimentacao a(d,op,v,ano,mes,dia);
          m.push_back(a);
          getline(in,linha);
          if(linha == "ContaCC"){break;}
          if(linha.size() == 0){break;}
        }
        if(linha.size() == 0){break;}
      }   
      Contacorrente co(nconta,sald,aux,m,limcred);
      this->setConta(co);
    }
    else if(linha == "ContaCP"){
      getline(in,linha);
      int nconta = stoi(linha);
      getline(in,linha);
      double saldo_p[28];
      for(int i =0; i < 28;i++){
        saldo_p[i] = stod(linha);
        getline(in,linha);
      }
      string ncli = linha;
      list<Cliente> c = get_clientes();
      Cliente aux;
      for (auto cli = c.begin() ; cli != c.end() ; cli++){
        if(ncli == cli->nomeCliente){
          aux.setNome(cli->nomeCliente);
          aux.setCpf_cnpj(cli->cpf_cnpj);
          aux.setEndereco(cli->endereco);
          aux.setFone(cli->fone);
          break;
        }
      }
      list<Movimentacao> m;
      while(linha != "ContaCP"){
        getline(in,linha);
        if(linha.size() == 0) {break;}
        if(linha=="mov") getline(in,linha);
        while((linha != "mov")){
          string ano = linha;
          getline(in,linha);
          string mes = linha;
          getline(in,linha);
          string dia = linha;
          getline(in,linha);
          string d = linha;
          getline(in,linha);
          char op = linha[0];
          getline(in,linha);
          double v = stod(linha);
          Movimentacao a(d,op,v,ano,mes,dia);
          m.push_back(a);
          getline(in,linha);
          if(linha == "ContaCP"){break;}
          if(linha.size() == 0){break;}
        }
        if(linha.size() == 0){break;}
      }      
      Contapoupanca co(nconta,aux,m,saldo_p);
      this->setConta(co);
    }
  }
  in.close();
}

string Banco::get_nome_banco(){
  return nomeBanco;
}

void Banco::extrato(int nconta, vector<string> di){
  list<Movimentacao> mov;
  for (auto i = listaContasPoupanca.begin();i!=listaContasPoupanca.end();i++){
    if(nconta == i->numConta){
      mov = i->extrato(di);
    }
  }
  for (auto i = listaContasCorrente.begin();i!=listaContasCorrente.end();i++){
    if(nconta == i->numConta){
      mov = i->extrato(di);
    }
  }
  // Imprimir extrato
  for (auto i = mov.begin();i!=mov.end();i++){
    cout<<i->dataMov[0]<<"/"<<i->dataMov[1]<<"/"<<i->dataMov[2]<<
      "   Tipo: "<<i->debitoCredito<<"  Valor: "<<i->valor<<
      "   Descricao: "<<i->descricao<<endl;
  }
}

void Banco::extrato(int nconta, vector<string> di, vector<string> df){
  list<Movimentacao> mov;
  for (auto i = listaContasCorrente.begin();i!=listaContasCorrente.end();i++){
    if(nconta == i->numConta){
      mov = i->extrato(di,df);
    }
  }
  for (auto i = listaContasPoupanca.begin();i!=listaContasPoupanca.end();i++){
    if(nconta == i->numConta){
      mov = i->extrato(di,df);
    }
  }
  // Imprimir extrato
  for (auto i = mov.begin();i!=mov.end();i++){
    cout<<i->dataMov[0]<<"/"<<i->dataMov[1]<<"/"<<i->dataMov[2]<<
      "   Tipo: "<<i->debitoCredito<<"  Valor: "<<i->valor<<
      "   Descricao: "<<i->descricao<<endl;
  }
}