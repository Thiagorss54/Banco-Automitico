#include <iostream>
#include <list>
#include <string>
#include <ctime>
#include "conta.h"
#include "cliente.h"
using namespace std;

int main(){
    Cliente *a = new Cliente("Joaoa","121212","Rua do joao","33333333");
    Conta ca(a);
    ca.print();
}