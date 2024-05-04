#include <iostream>
#include <string>
#include "classes.hpp"
#include <vector>

using namespace std;
// test for windows or linux and use define if possible

char menu();
string setUserCode();
void encryptText(Cipher *secret);
void decryptText(Cipher *secret);

int main(){

    Cipher *secret = nullptr;
    char input;
    while (true){
        
        system("clear");
        input = menu();
        switch (toupper(input)){
        
            case ('1'):
                system("clear");
                encryptText(secret);
                
            break;

            case ('2'):
                system("clear");
                decryptText(secret);
            
            break;
            
            case ('3'):
                system("clear");
                if (secret != nullptr){
                    cout  << "User code already exists! \nTry the re-generate option on main menu.";
                    cin.get();
                    break;
                };
                secret = new Cipher(setUserCode());
                cout<< endl<< "The code was saved. Table generated."<<endl;
                cin.get();
            break;
            
            case ('4'):
            
            break;
            
            case ('0'):
                system("clear");
                cout<<"Exiting..."<<endl;
                return 0;
            
            break;  
            
            default:
                system("clear");
                cout << "Error! Invalid option."<<endl;
                cin.get();
            break;          
                                            
        
        };
    
    };  
    return 0;
};


void decryptText(Cipher *secret){

    string input;
    cout <<"------Encrypt Text------"<<endl;
    cout << endl << "Insert text: ";
    getline(cin, input);
    cout << endl <<"Decrypted text: "<< secret->GetDecryptedText(input) << endl;
    cin.get();

};


void encryptText(Cipher *secret){

    string input;
    cout <<"------Encrypt Text------"<<endl;
    cout << endl << "Insert text: ";
    getline(cin, input);
    secret->SetInputText(input);
    cout << endl <<"Encrypted text: "<< secret->GetEncryptedText() << endl;
    cout << "\n\n [INFO] Note that some characters might not be displayed correctly. \n The text was also stored in a file named data.txt in this directory.";
    cin.get();
    
};


string setUserCode(){

    string input;
    cout <<"------Set User Code------"<<endl;
    cout << endl << "Insert new User Code: ";
    getline(cin, input);
    
    return(input);
    
};

char menu(){
    char input;
    cout <<"======MENU======"<<endl;
    cout << " 1 - Encrypt Text \n 2 - Decrypt Text \n 3 - Set User Code \n 4 - Re-generate Conv. Table \n 0 - Exit "<< endl;
    cout << "================ \nEnter Option:";
    cin.clear();
    cin >> input;    
    cin.ignore();
    
    return (input);
}; 

