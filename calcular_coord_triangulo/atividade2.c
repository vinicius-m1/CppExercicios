#include <iostream>
#include <cmath>
using namespace std;


double maior(double a,double b,double c){
    double maior;
    maior = a;                
    if (b>a){maior = b;};
    if (c>a){maior = c;};
    if (b>c){maior = b;};
    return (maior);
};

double distancia(double x1d,double y1d,double x2d,double y2d){
    return sqrt (pow((x2d - x1d),2) + pow((y2d-y1d),2));
};

double angulo(double lado,double hipotenusa){
    
    return (asin(lado/hipotenusa));

};

double area(double a,double b,double c){
    double s;
    s = ((a+b+c)/2);
    return (sqrt(s*(s-a)*(s-b)*(s-c)));

};

int main (){

    double x1,x2,x3,y1,y2,y3;
    cout << "Digite as coordenadas do primeiro ponto (x, y): ";
    cin >> x1 >> y1;
    cout << "Digite as coordenadas do segundo ponto (x, y): ";
    cin >> x2 >> y2;
    cout << "Digite as coordenadas do terceiro ponto (x, y): ";
    cin >> x3 >> y3;
    
    double ladoA = distancia(x1,y1,x2,y2);
    double ladoB = distancia(x2,y2,x3,y3);
    double ladoC = distancia(x1,y1,x3,y3);
    
    double hipotenusa = maior(ladoA,ladoB,ladoC);
    
    double anguloA = angulo(ladoB, hipotenusa);
    double anguloB = angulo(ladoA, hipotenusa);
    double anguloC = angulo(ladoC, hipotenusa);
    
    double areaTriangulo = area(ladoA,ladoB,ladoC);
     
    cout << "Lado 1: " << ladoA << " Lado 2: " << ladoB << " Lado 3: " << ladoC << "\n";
    
    cout << "Angulo A: " << anguloA << " Angulo B: " << anguloB << " Angulo C: " << anguloC << "\n";
    
    cout << "Area do triangulo é: " << areaTriangulo << "\n";
        
return 0;
};
