
using namespace std;

class Vehicle{

    protected:
        float quilometragem = 0;
        string m_placa, m_desc;
        vector<pair<string, float>> viagens;
        vector<string> cidades;
    public:
    
        Vehicle(){};
        
        
        vector<string> GetCidades(){return cidades;};
        
        
        void AddViagem(pair<string, float> viagem, string cidade){
            viagens.push_back(viagem);
            quilometragem = (quilometragem + viagem.second);
            cidades.push_back(cidade);
        };  
        
        //virtual string Consumo()= 0;
        // por algum erro nao rodou, mas o codigo do polimorfismo esta aqui
        
        
        string GetPlaca(){return m_placa;};
        
        float GetQuilometragem(){return quilometragem;};
};



class Car : public Vehicle{

    protected:
    
    public:
    
    Car(string placa, string desc){
        m_placa = placa;
        m_desc = desc;
    };
      
    string Consumo(){return ("14 km/l");};
};


class Bus : public Vehicle{

    protected:
    
    public:
    
    Bus(string placa, string desc){
        m_placa = placa;
        m_desc = desc;
    };
    
    string Consumo(){return ("8 km/l");};
};


class LightTruck : public Vehicle{

    protected:
    
    public:
    
    LightTruck(string placa, string desc){
        m_placa = placa;
        m_desc = desc;
    };
    
    string Consumo(){return ("5 km/l");};
};


class HeavyTruck : public Vehicle{

    protected:
    
    public:
    
    HeavyTruck(string placa, string desc){
        m_placa = placa;
        m_desc = desc;
    };
    
    string Consumo(){return ("3 km/l");};  
};

