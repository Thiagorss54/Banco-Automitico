#include "interface.h"


    int nconta;
    double valor;
    
    
    void cls(){
        system("cls");
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
        system("cls");
        cout << "\n\n\n\t\t\t  " << nomeBanco_ << endl << endl << endl ;
        cout << "1  Cadastrar cliente";
        cout << "\t\t\t\t2  Criar Conta" << endl<< endl;
        cout << "3  Excluir Cliente" ;
        cout << "\t\t\t\t4  Excluir Conta" << endl<< endl;
        cout << "5  Deposito" ;
        cout << "\t\t\t\t\t6  Saque" << endl<< endl;
        cout << "7  Transferencia" ;
        cout << "\t\t\t\t8  CobrarTarifa" << endl<< endl;
        cout << "9  Cobrar CPMF" ;
        cout << "\t\t\t\t\t10 Saldo" << endl<< endl;
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
        cout << "Numero da Conta:\t" ;
        cin >> nconta;
        cout << "Valor:\t";
        cin >> valor;
        int conf = confirmacao();
        if(conf == 0){
            NU->deposito(nconta,valor);
            cout << "   Operacao realizada.  " << endl;
            NU->gravar_dados();
           

        }
        else if(conf == 1){
            deposito();
        }
        else
           main();
    }
    void Interface::saque(){
        cls();
        cout << "\t\t\t Saque\n\n";

    }
    void Interface::transferencia(){
        cls();
        cout << "\t\t\t Transferencia\n\n";
    }
    void Interface::cobrarTarifa(){
        cls();
        cout << "\t\t\t Cobrar Tarifa\n\n";
    }
    void Interface::cobrarCPMF(){

    }
    void Interface::saldo(){
        cls();
        cout << "\t\t\t Saldo\n\n";
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
            default: system("cls"); cout <<" \t\t\t Operacao INVALIDA" << endl<< endl;system("pause");menu();
        }
        system("pause");
    }

