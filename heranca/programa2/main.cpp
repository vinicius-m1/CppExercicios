#include <iostream>
#include "classes.hpp"
#include <string>

#include <vector>
using namespace std;


int main(){

    Empregado e1("João Silva", 1500);

    Gerente g1("Pedro Paulo Pereira Santos Junior de Oliveira Silva Gomes", 5000, "Dep 12");

    Vendedor v1("Saulo Salso Melo", 2000, 450);


    cout << endl<<"\n\n\n       Vector EMPREGADOS"<<endl;
    
    vector<Empregado> Empregados;
    Empregados.push_back(e1);
    Empregados.push_back(g1);
    Empregados.push_back(v1);
    
    for (int i=0; i<Empregados.size(); i++){
        cout << endl << (Empregados.at(i)).toString();  
    };







    cout << endl<<"\n\n\n       Vector GERENTES"<<endl;
    
    vector<Gerente> Gerentes;
    
    Gerentes.push_back(g1);
    
    
    for (int i=0; i<Gerentes.size(); i++){
        cout << endl << (Gerentes.at(i)).toString();  
    };






    cout << endl<<"\n\n\n       Vector VENDEDORES"<<endl;
    
    vector<Vendedor> Vendedores;
    
    
    Vendedores.push_back(v1);
    
    for (int i=0; i<Vendedores.size(); i++){
        cout << endl << (Vendedores.at(i)).toString();  
    };




















};
