using namespace std;




class Empregado{
        
    private:
          
        
    protected: 
    
        float m_salario=0;
    
    public:
        string m_nome;  
        string GetName(){return m_nome;};
        
        Empregado(){};
        
        Empregado(const string nome, const float salario){
            m_nome = nome;
            m_salario = salario;
        };
        
        string toString(){
            string output = "Name: "+m_nome;
            return output;
        };

};



// =====================================================================================

class Gerente : public Empregado {

    private:
        string m_departamento;
    

    protected:



    public:

        string GetDepartamento(){return m_departamento;};
        
        Gerente(const string nome, const float salario, const string departamento){
            m_nome = nome;
            m_salario = salario;
            m_departamento = departamento;
        };

        string toString(){
            string output = "Name: "+m_nome+" Department: "+ m_departamento;
            return output;
        };    


}; 


// =============================================================================================


class Vendedor : public Empregado {

    private:
        float m_comissao;
    

    protected:



    public:

        Vendedor(const string nome, const float salario, const float comissao){
            m_nome = nome;
            m_salario = salario;
            m_comissao = comissao;
            
        };

        string toString(){
            string output = "Name: "+m_nome+"\n Salario: " + to_string(m_salario)+"\n Salario c/comissão: "+ to_string(Vendedor::CalcularSalario())+"\n Comissão: "+ to_string(m_comissao);
            return output;
        };    


        float CalcularSalario(){
            return (m_comissao + m_salario);
        };


}; 














