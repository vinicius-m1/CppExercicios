#include "client.hpp"
#include "account.hpp"
#include <vector>
#include <string>

char menu();
int createAccount(vector<Client> *clientList, vector<ContaCorrente*> *accountList);
int listData(const vector<Client> *clientList, const vector<ContaCorrente*> *accountList)
int createSpecialAccount();
int insertClient(vector<Client> *clientList);
int deposit();
int transfer();
int withdraw();

// -------------------------------------------------------------------------------------------------


int deposit(){
    cout <<"==========Deposit=========="<<endl;
    cin.get();
    return 0;

};

int transfer(){
    cout <<"==========Transfer=========="<<endl;
    cin.get();
    return 0;

};

int withdraw(){
    cout <<"==========Withdraw=========="<<endl;
    cin.get();
    return 0;

};

int createSpecialAccount(){
    cout <<"==========Special Account=========="<<endl;
    cin.get();
    return 0;

};

int listData(const vector<Client> *clientList, const vector<ContaCorrente*> *accountList){
    cout <<"==========List Data=========="<<endl;
    
    cout << "Clients data: "<<endl;
    for (int i=0; i<clientList->size(); i++){
        cout << clientList->at(i).GetInformation <<endl;
    };
    
    cout << "\n\n\n Clients data: "<<endl;
    
    for (int i=0; i<accountList->size(); i++){
        cout << accountList->at(i).GetInformation <<endl;
        // criar metodo em account
    };
    
    
    cin.get();
    return 0;

};

int insertClient(vector<Client> *clientList){
    cout <<"==========Insert Client=========="<<endl;
    
    string name, address, job;
    float income;
    
    cout << "Client name: ";
    getline(cin,name);
    cout << endl <<"Client address: ";
    getline(cin,address);    
    cout << endl <<"Client job: ";
    getline(cin,job);  
    cout << endl <<"Client income: ";
    cin.clear();
    cin >> income;  
    cin.ignore();
    
    clientList->push_back(Client(name, address, job, income));
    
    cout << endl << "[INFO] Client added."<<endl;
    
    cin.get();
    return 0;

};



int createAccount(vector<Client> *clientList, vector<ContaCorrente*> *accountList){

    if (clientList->empty()){
        cout<< "[INFO] No Available clients.";
        cin.get()
        return 0;  
    };
        
    
    cout <<"==========Create Account=========="<<endl;
    
    cout << "Select client:"<<endl;
    for (int i=0;i<clientList->size();i++)
        cout<<"["<<i<<"] "<< clientList->at(i).GetName() <<endl;
    
    int input;
    cin.clear();
    cin >> input;    
    cin.ignore();
    if (input > clientList->size() || input < 0){return 1;};
 
    cout << endl <<"Account balance: ";
    float balance;
    cin.clear();
    cin >> balance;    
    cin.ignore();
    
    accountList->push_back(new ContaCorrente( &(clientList->at(input)) , balance));      
    
    cout << endl << "[INFO] Account Created";
    cin.get();
    return 0;

};


char menu(){
    system("clear");
    cout << "========Menu======= \n 1 - Insert Client 👤️ \n 2 - Create Account 💳️ \n 3 - Deposit 💲️ \n 4 - Transfer 💱️ \n 5 - Withdraw 💰️ \n 6 - Create Special Account 🧾️ \n 7 - List Data 🎲️ \n 0 - Exit 🚪️" <<endl;
    cout << "===================\nOption: ";

    char input;
    cin.clear();
    cin >> input;
    cin.ignore();
    
    return toupper(input);
};



int main()
{
    //implementar o menu de forma que clientes possam ser inseridos, e operações sobre as contas realizadas


    //lista de clientes
    vector<Client> clientList;

    vector<ContaCorrente*> accountList;

    while (true){
        system("clear");
        
        switch(menu()){
        
            case('0'):
                system("clear");
                return 0;
                break;
                
            case('1'):
                system("clear");
                insertClient(&clientList);
                break;
                
            case('2'):
                system("clear");
                createAccount(&clientList, &accountList);
                break;

            case('3'):
                system("clear");
                deposit();
                break;
                
            case('4'):
                system("clear");
                transfer();
                break;
               
            case('5'):
                system("clear");
                withdraw();
                break;
                
            case('6'):
                system("clear");
                createSpecialAccount();
                break;  
                
            case('7'):
                system("clear");
                listData(&clientList, &accountList);
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


