#include <vector>
using namespace std;
class Policy{

    private:
    
    protected:
        vector<size_t> * m_tasks;            
    
    
    public:

        Policy(){};
        ~Policy(){};
};

// ------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------

class PolicyOne : public Policy{

    private:
    
        
    
    
    public:
        PolicyOne(vector<size_t> * tasks){m_tasks = tasks;};
        int Process();
        ~PolicyOne(){};        

};



// ------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------



class PolicyTwo : public Policy{

    private:
    
           
    
    
    public:

        PolicyTwo(vector<size_t> * tasks){m_tasks = tasks;};   
        int Process();
        
        ~PolicyTwo(){};         
    
};


class PolicyThree : public Policy{

    private:
    
           
    
    
    public:

        PolicyThree(vector<size_t> * tasks){m_tasks = tasks;};   
        int Process();
        
        ~PolicyThree(){};         
    
};

