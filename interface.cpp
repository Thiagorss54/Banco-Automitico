#include "interface.h"


    int nconta,conf,Inicio=0;
    double valor;
    
    
    void cls(){
         system("cls");
        
    }

    int confirmacao(){
        char confirmacao;
        cout << endl << "CONFIRMAR (C)       Retornar(R)      ANULAR (A)   " << endl;
        cin >> confirmacao;
        cout<< "\r";
        cout << endl <<endl;
        if(confirmacao == 'C'){
            return 0;
        }
        else if(confirmacao == 'R'){
            return 1;
        }
        else
            return 2;
        
    }
    vector <string> dataDehoje(){
        vector<string> dataMov;
    time_t rawtime;
	string a;
	struct tm * timeinfo;
	char buffer [80]; 
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime (buffer,80,"%Y",timeinfo);
	a = buffer;
	dataMov.push_back(a);
	strftime (buffer,80,"%m",timeinfo);
	a = buffer;
	dataMov.push_back(a);
	strftime (buffer,80,"%d",timeinfo);
	a = buffer;
	dataMov.push_back(a);
    return dataMov;
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
         cls();
        cout << "\t\t\t CADASTRO DE CLIENTE\n\n\n";
        cout << "Digite o nome do cliente:\t  " ;
        string cli;
        cin >> cli;
        cout << "Digite o cpf_cnpj do cliente:\t  " ;
        string cpf;
        cin >> cpf;
        cout << "Digite o telefone do cliente:\t  " ;
        string tel;
        cin >> tel;
        cout << "Digite o endereco do cliente:\t  " ;
        string ende;
        cin >> ende;
        conf = confirmacao();
        if(conf == 0){
        Cliente aux(cli,cpf,ende,tel);
       
        NU->setCliente(aux);
        NU->gravar_dados();
        cls();
        cout << "\t\t\t CADASTRO DE CLIENTE\n\n\n";
        cout << "\t\t\t  Cliente cadastrado!" << endl;
        cout << endl << endl << endl;
        system("pause");
        }
        else if(conf == 1){
            system("pause");
            cadastrarCliente();
        }
        main();
        
        
        
       
        

    }
    void Interface::criarConta(){
        //imprimir o nome dos clientes pra pessoa digitar qual que ela quer relacionar a uma conta
        // usar um cliente aux 
         cls();

         cout << "\t\t\t Criar Conta\n\n\n";

        int cont =0,achou=0;
       list <Cliente> aux = NU->get_clientes();
       
        for (auto j = aux.begin(); j !=aux.end(); j++,cont++) {
            cout << "Cliente " << cont << endl;
            cout<< " Nome: "<< j->getNome()<< endl;
           
            cout << endl;
        }
        cout << "Digite o nome do Cliente: ";
        string nome;
        cin>>nome;
        
        cont =0;
        for (auto j = aux.begin(); j !=aux.end(); j++,cont++) {

            if(nome == j->getNome()){
                achou=1;

                //cout<<"cliente valido" << endl;
                conf = confirmacao();
                if(conf == 0){

                    int tipo_c = 0;
                    while (tipo_c !=1 && tipo_c !=2)
                    {   
                        cls();
                        cout << "\t\t\t Criar Conta\n\n\n";
                        cout<<"1  Conta poupanca                      2  Conta corrente "<<endl<<endl<<endl;
                        cin>>tipo_c;
                        if(tipo_c == 1){
                            conf = confirmacao();
                            if(conf==0){
                            NU->criar_conta_poupanca(*j);
                            cls();
                            cout << "\t\t\t Criar Conta\n\n\n";
                            cout <<  "                      Sua conta foi criada." << endl;
                            }
                            else if(conf == 1){
                                criarConta();
                            }
                        }
                        else if(tipo_c == 2){
                            conf = confirmacao();
                            if(conf==0){
                            NU->criar_conta_corrente(*j);
                            cls();
                            cout << "\t\t\t Criar Conta\n\n\n";
                            cout << "\t\t Sua conta foi criada." << endl;
                            }
                            else if(conf == 1){
                                criarConta();
                            }
                        }
                    }
                    NU->gravar_dados();
                    // cout<<"criou ---------------" <<endl;
                    cout << endl << endl << endl;
                    system("pause");
                }
                else if(conf == 1){
                    cls();
                    criarConta();
                }           
            }
           
            
            
     
        }
         if(achou=0) {
                cls();
                int voltar=0;
                cout << "\t\t\t Criar Conta\n\n\n";
                cout<<"Cliente " <<nome << " inexistente" <<endl<< endl;
                cout << "1  Digitar novamente        2 Voltar para o inicio"<< endl;
                cin >> voltar;
                if(voltar==1){
                cls();
                criarConta();
                }
                
            }
            main();
        
    }
    void Interface::excluirCliente(){
        cls();
        string cpfCnpj;
        cout << "\t\t\t Excluir Cliente\n\n\n";
        cout << "Cpf/Cnpj:\t  " ;
        cin >> cpfCnpj;
        
        conf = confirmacao();
        if(conf == 0){
            cls();
            NU->excluir_cliente(cpfCnpj);
            NU->gravar_dados();
            cls();
             cout << "\t\t\t Excluir Cliente\n\n\n";
             cout<< "\t\t\tCliente excluido"<<endl;
            cout << endl << endl << endl;
            cout << endl << endl << endl;
            system("pause");
        }
        else if(conf == 1){
            excluirCliente();
        }
           main();
    }
    void Interface::excluirConta(){
        cls();
        
        cout << "\t\t\t Excluir Conta\n\n\n";
        cout << "Numero da Conta:\t  " ;
        cin >> nconta;
        conf = confirmacao();
        if(conf == 0){
            cls();
            NU->excluir_conta(nconta);
            NU->gravar_dados();
             cout << "\t\t\t Excluir Conta\n\n\n";
             cout<< "           Conta excluida"<<endl;
            cout << endl << endl << endl;
            system("pause");
        }
        else if(conf == 1){
            excluirConta();
        }
           main();

    }
    void Interface::deposito(){
        
        cls();
        cout << "\t\t\t Deposito\n\n\n";
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
        cout << "\t\t\t Saque\n\n\n";
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
        cout << "\t\t\t Transferencia\n\n\n";
        cout << "Numero da Conta :\t  " ;
        cin >> nconta_O;
        cout << "Numero da Conta Destino:\t  ";
        cin >> nconta_D;
        cout << "Valor:\t  ";
        cin >> valor;
        conf = confirmacao();
        if(conf == 0){
            NU->transferencia_conta(nconta_O,nconta_D,valor);
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
        cout << "\t\t\t Pagamento da Tarifa\n\n\n";
        cout << "Confirmar pagamento?" << endl;
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
        cout << "\t\t\t CPMF\n\n\n";
        cout << "Confirmar pagamento?" << endl;
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
        cout << "\t\t\t Saldo\n\n\n";
        cout << "Numero da Conta:\t  " ;
        cin >> nconta;
        conf = confirmacao();
        if(conf == 0){
            NU->saldo(nconta);
            system("pause");
        }
        else if(conf == 1){
            saldo();
        }
           main();
    }
    void Interface::extrato(){
        cls();
        int n;
        cout << "\t\t\t Extrato\n\n\n";
        cout<< "Numero da conta: ";
        cin >> n;
        conf = confirmacao();
        if(conf ==0){
            cls();
            vector<string> aux = dataDehoje();
            cout << "\t\t\t Extrato\n\n\n";
            NU->extrato(n,aux);
            cout<< endl << endl;
            system("pause");

        }
        else if(conf ==1){
            extrato();
        }
        
        main();
      
    }
    void Interface::listarClientes(){
        cls();
        cout << "\t\t\t Clientes\n\n\n";
        int cont=1;
        list <Cliente> aux = NU->get_clientes();
        for (auto j = aux.begin(); j !=aux.end(); j++,cont++) {
            cout << "Cliente " << cont << endl;
            j->print();
            cout << endl;
        }
        cout << endl << endl << endl;
        system("pause");
        main();

    }
    void Interface::listarContas(){
        cls();
        int g,g2;
        cout << "\t\t\t Contas\n\n\n";
        list <Contapoupanca> aux = NU->get_contaspoupanca();
        cout << "           Contas Poupanca: " << endl<<endl;
        for (auto j = aux.begin(); j !=aux.end(); j++) {
            
            cout << "numero = " << j->numConta << endl;
            cout << "cliente: "<< j->cliente.getNome() << endl;
            cout << "saldo = " << j->saldo << endl;
            cout << endl;
            }
             list <Contacorrente> aux1 = NU->get_contascorrente();
        cout <<"           Contas Corrente: " << endl<<endl;
        for (auto cc = aux1.begin(); cc !=aux1.end(); cc++) {
            
            cout << "numero = " << cc->numConta << endl;
            cout << "cliente: "<< cc->cliente.getNome() << endl;
            cout << "saldo = " << cc->saldo << endl;
            cout << endl;
            }

        cout << endl << endl << endl;
        system("pause");
        main();

    }
    void Interface::main(){
        if(Inicio==0)
            NU->ler_dados();
        Inicio=1;
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
    }

