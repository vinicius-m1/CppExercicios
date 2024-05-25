#include <string>
using namespace std;

class Cards{

    protected:
        string recipient;
        
    public:
    
        //Cards(string str){recipient = str;};
        virtual int ShowMessage() = 0;    

};

class ChristmasCard : public Cards{

    public:
    
        ChristmasCard(string str){recipient = str;};
        virtual int ShowMessage() override {
            cout << "Happy Holidays, " << recipient << "!" << endl;  
            return 0;      
        }; 
        
};


class BirthdayCard : public Cards{

    public:
        BirthdayCard(string str){recipient = str;};
        virtual int ShowMessage() override {
            cout << "Happy Birthday, " << recipient << "!" << endl; 
            return 0;       
        }; 
        
};


class ValentinesCard : public Cards{

    public:
        ValentinesCard(string str){recipient = str;};
        
        virtual int ShowMessage() override{
            cout << "Happy Valentines day, " << recipient << "!" << endl;     
            return 0;   
        }; 
        
};
