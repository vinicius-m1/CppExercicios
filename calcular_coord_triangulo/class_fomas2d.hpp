// criar classes para: Point2d, Circle, Square, Triangle, Polygon
// calcular(com metodos dentro da classe) area(todos), circunferencia, raio, angulo, perimetro(todos)

#include <iostream>
#include <string>
#include "class_fomas2d.cpp"
// #include "outro_arquivo.hpp" 

using namespace std;




int main(){
    int value;
    Teste obj_instanc; 
    
    cin >> (value);
    cin.ignore();
    obj_instanc.SetVar(value);
    cout << obj_instanc.GetVar()<<endl;

    //cout << obj_instanc.m_var; trying to access private value


};


