#include "interface.h"


    int nconta,conf;
    double valor;
    
    
    void cls(){
        // system("cls");
        cout << "\n\n\n\n\n";
    }

    int confirmacao(){
        char confirmacao;
        cout << "CONFIRMAR (C)       Retornar(R)      ANULAR (A)   " << endl;
        cin >> confirmacao;
        if(confirmacao == 'C'){
            return 0;
        }
        else if(confirmacao == 'R'){
            return 1;
        }
        else
            return 2;
        
    }
  
    Interface::Interface(string nomeBanco):nomeBanco_(nomeBanco){
        NU = new Banco("teste");
    }

    void Interface::menu(){
        cls();
        cout << "\n\n\n\t\t\t  " << nomeBanco_ << endl << endl << endl ;
        cout << "1  Cadastrar cliente";
        cout << "\t\t\t\t2  Criar Conta" << endl<< endl;
        cout << "3  Excluir Cliente" ;
        cout << "\t\t\t\t4  Excluir Conta" << endl<< endl;
        cout << "5  Deposito" ;
        cout << "\t\t\t\t\t6  Saque" << endl<< endl;
        cout << "7  Transferencia" ;
        cout << "\t\t\t\t8  Tarifa" << endl<< endl;
        cout << "9  CPMF" ;
        cout << "\t\t\t\t\t\t10 Saldo" << endl<< endl;
        cout << "11 Extrato" ;
        cout << "\t\t\t\t\t12 Listar Clientes" << endl<< endl;
        cout << "13 Listar Contas";
        cout << "\t\t\t\t0 FINALIZAR" << endl<< endl;
        cout << endl ;
        

    }
    void Interface::cadastrarCliente(){

    }
    void Interface::criarConta(){
        //imprimir o nome dos clientes pra pessoa digitar qual que ela quer relacionar a uma conta
        // usar um cliente aux 
    }
    void Interface::excluirCliente(){

    }
    void Interface::excluirConta(){

    }
    void Interface::deposito(){
        
        cls();
        cout << "\t\t\t Deposito\n\n";
        cout << "Numero da Conta:\t  " ;
        cin >> nconta;
        cout << "Valor:\t  ";
        cin >> valor;
        conf = confirmacao();
        if(conf == 0){
            NU->deposito(nconta,valor);
            cout << "        Operacao realizada.  " << endl;
            NU->gravar_dados();
            system("pause");
        }
        else if(conf == 1){
            deposito();
        }
           main();
    }
    void Interface::saque(){
        cls();
        cout << "\t\t\t Saque\n\n";
        cout << "Numero da Conta:\t  " ;
        cin >> nconta;
        cout << "Valor:\t  ";
        cin >> valor;
        conf = confirmacao();
        if(conf == 0){
            NU->saque(nconta,valor);
            cout << "        Operacao realizada.  " << endl;
            NU->gravar_dados();
            system("pause");
        }
        else if(conf == 1){
            saque();
        }
           main();

    }
    void Interface::transferencia(){
        int nconta_O, nconta_D;
        cls();
        cout << "\t\t\t Transferencia\n\n";
        cout << "Numero da Conta:\t  " ;
        cin >> nconta_O;
        cout << "Conta Destino:\t  ";
        cin >> nconta_D;
        cout << "Valor:\t  ";
        cin >> valor;
        conf = confirmacao();
        if(conf == 0){
            NU->transferencia_conta(nconta_O,nconta_D,valor);
            cout << "        Operacao realizada.  " << endl;
            NU->gravar_dados();
            system("pause");
        }
        else if(conf == 1){
            transferencia();
        }
           main();
    }
    void Interface::cobrarTarifa(){
        cls();
        cout << "\t\t\t Pagamento da Tarifa\n\n";
        cout << "Confirmar pagamento?   ";
        conf = confirmacao();
        if(conf == 0){
            NU->tarifa();
            cout << "        Operacao realizada.  " << endl;
            NU->gravar_dados();
            system("pause");
        }
        else if(conf == 1){
            cobrarTarifa();
        }
           main();

    }
    void Interface::cobrarCPMF(){
        cls();
        cout << "\t\t\t CPMF\n\n";
        cout << "Confirmar pagamento?   ";
        conf = confirmacao();
        if(conf == 0){
            NU->debitar_cpmf();
            cout << "        Operacao realizada.  " << endl;
            NU->gravar_dados();
            system("pause");
        }
        else if(conf == 1){
            cobrarCPMF();
        }
           main();

    }
    void Interface::saldo(){
        cls();
        cout << "\t\t\t Saldo\n\n";
        cout << "Numero da Conta:\t  " ;
        cin >> nconta;
        conf = confirmacao();
        if(conf == 0){
            NU->saldo(nconta);
            cout << "        Operacao realizada.  " << endl;
            NU->gravar_dados();
            system("pause");
        }
        else if(conf == 1){
            saldo();
        }
           main();
    }
    void Interface::extrato(){
      
    }
    void Interface::listarClientes(){

    }
    void Interface::listarContas(){

    }
    void Interface::main(){
        NU->ler_dados();
        menu();
        Banco banco(nomeBanco_);
        int funcao;
        cin >> funcao;
        switch(funcao){
            case 1: cadastrarCliente(); break;
            case 2: criarConta();break;
            case 3: excluirCliente();break;
            case 4: excluirConta();break;
            case 5: deposito();break;
            case 6: saque();break;
            case 7: transferencia();break;
            case 8: cobrarTarifa();break;
            case 9: cobrarCPMF();break;
            case 10: saldo();break;
            case 11: extrato();break;
            case 12: listarClientes();break;
            case 13: listarContas();break;
            case 0: exit(0);break;
            default: cls(); cout <<" \t\t\t Operacao INVALIDA" << endl<< endl;system("pause");menu();
        }
        system("pause");
    }

