#include <iostream>
#include <vector>
#include <string>
#include "classes.hpp"
using namespace std;

int NewVehicle();
int NewTrip();
int ShowReports();
int ShowVehicleHistory();



int NewVehicle(vector<Vehicle> *Vehicles){
    cout << "new vehicle" << endl;
    
    cout << endl <<"Tipo de carro \n 1 - Car \n 2 - Bus \n 3 - LightTruck \n 4 - HeavyTruck" <<endl;
    char tipo;
    string placa, desc;
    cin.clear();
    cin >> (tipo);
    cin.ignore();
    
    cout << endl << "Placa do carro: "<<endl;
    getline(cin, placa);
    
    for (int i=0; i<Vehicles->size();i++){
        
        if (Vehicles->at(i).GetPlaca() == placa){
            cout <<endl <<"placa ja existe:"<<endl;
            cin.get();
            return 0;
        };
    };
    
    
    cout << endl << "Descrição do carro: "<<endl;
    getline(cin, desc);    
    
    switch (tipo){
    
        case ('1'):
            Vehicles->push_back( Car(placa, desc) );
            cout << endl<< "car added."<<endl;
            cin.get();
            break;

        case ('2'):
            Vehicles->push_back( Bus(placa, desc) );
            cout << endl<< "car added."<<endl;
            cin.get();
            break;
        
        case ('3'):
            Vehicles->push_back( LightTruck(placa, desc) );
            cout << endl<< "car added."<<endl;
            cin.get();
            break;        
    
        case ('4'):
            Vehicles->push_back( HeavyTruck(placa, desc) );
            cout << endl<< "car added."<<endl;
            cin.get();
            break;    
    };
    
       
    
    //cin.get();
    return 0;
};

int NewTrip(vector<Vehicle> *Vehicles){
    cout << "new trip" << endl;
    
    string placa,destino;
    float km;
    pair<string,float> viagem;
    cout<< endl << "Placa do carro:"<<endl;
    getline(cin,placa);
    cout<< endl << "Cidade Destino:"<<endl;
    getline(cin,destino);
    cout<< endl << "Distancia (km):"<<endl;
    cin.clear();
    cin >> (km);
    cin.ignore();
    
    viagem.first = placa;
    viagem.second = km;
    for (int i=0; i<Vehicles->size();i++){
        
        if (Vehicles->at(i).GetPlaca() == placa){
            cout <<endl <<"veiculo encontrado placa:" << placa<<endl;
            Vehicles->at(i).AddViagem(viagem, destino);
            break;
        };
    };
    cout << "viagem adicionada";
    
    cin.get();
    return 0;
};

int ShowReports(vector<Vehicle> *Vehicles){
    cout << "show reports" << endl;
    
    for (int i=0; i<Vehicles->size();i++){
        cout << endl << "placa: "<< Vehicles->at(i).GetPlaca();
        cout << " km total: "<< Vehicles->at(i).GetQuilometragem();
        //cout << "consumo: "<< Vehicles->at(i).Consumo();
        // por algum erro nao rodou, mas o codigo do polimorfismo esta aqui (e no hpp)
        
    }
    
    cin.get();
    return 0;
};

int ShowVehicleHistory(vector<Vehicle> *Vehicles){
    cout << "Show Vehicle History" << endl;
    cout << "placa:"<<endl;
    string placa;
    getline (cin,placa);
        for (int i=0; i<Vehicles->size();i++){
        
            for (int j=0; j<Vehicles->at(i).GetCidades().size() ;j++){cout << Vehicles->at(i).GetCidades().at(j) << endl; };
        //cout << "consumo: "<< Vehicles->at(i).Consumo();
        // por algum erro nao rodou, mas o codigo do polimorfismo esta aqui (e no hpp)
        
    }
    
    
    cin.get();
    return 0;
};






char menu(){
    system("clear");
    cout << "========Menu======= \n 1 - Insert New Vehicle \n 2 - Insert a trip \n 3 - Show Reports \n 4 - Show history by vehicle \n 0 - Exit " <<endl;
    cout << "===================\nOption: ";

    char input;
    cin.clear();
    cin >> input;
    cin.ignore();
    
    return toupper(input);
};



int main()
{

    vector<Vehicle> Vehicles;
     

    while (true){
        system("clear");
        
        switch(menu()){
        
            case('1'):
                system("clear");
                NewVehicle(&Vehicles);
                break;
                
            case('2'):
                system("clear");
                NewTrip(&Vehicles);
                break;

            case('3'):
                system("clear");
                ShowReports(&Vehicles);
                break;
                
            case('4'):
                system("clear");
                ShowVehicleHistory(&Vehicles);
                break;

            case('0'):
                system("clear");
                return 0;
                break;
               
            default:
                system("clear");
                cout << "[INFO] - Invalid option."<<endl;
                cin.get();
                break;           
        };
    };


    return 0;
};
