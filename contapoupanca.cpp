#include "contapoupanca.h"

bool Contapoupanca::debitar(double v, string d){
    time_t rawtime;
	string a;
	struct tm * timeinfo;
	char buffer [80]; 
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime (buffer,80,"%d",timeinfo);
	a = buffer;
	int dia = stoi(a);
    int contador = 1;
    
    if(dia == 29 || dia == 30 || dia == 31){
        dia = 28;
    }

    while(Poupanca[dia - 1] - v < 0 && contador < 28){
        contador ++;
        if(dia != 1){
            dia--;
        }else{
            dia += 27;
        }
    }
    
    if(Poupanca[dia - 1] - v >= 0){
        Poupanca[dia - 1] -= v;
        Movimentacao mov(d,'D',v); 
		//movimentacoes.push_back(mov);
        return true;
    }else{
        cout << "Saldo insuficiente" << endl;
        return false;
    }
}
void Contapoupanca::creditar(double v,string d){
    time_t rawtime;
	string a;
	struct tm * timeinfo;
	char buffer [80]; 
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime (buffer,80,"%d",timeinfo);
	a = buffer;
	int dia = stoi(a);

    if(dia == 29 || dia == 30 || dia == 31){
        dia = 28;
    }

    Poupanca[dia - 1] += v;
    Movimentacao mov(d,'C',v); 
   // movimentacoes.push_back(mov);
	
}
void Contapoupanca::Rendimento_Poupanca(){
    time_t rawtime;
	string a;
	struct tm * timeinfo;
	char buffer [80]; 
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime (buffer,80,"%d",timeinfo);
	a = buffer;
	int dia = stoi(a);

    Poupanca[dia - 1] += Poupanca[dia - 1] * 0.01;
}




