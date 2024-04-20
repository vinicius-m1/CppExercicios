#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;



int readFile(string *input){
    string filename;
    system ("ls");
    cout<< endl <<"Nome do arquivo:";
    getline(cin,filename);

    ifstream filedata(filename);
    if (filedata.is_open() == true){
    
        getline( filedata, *input, '\0');
        
        
        filedata.close();
    };

    return 0;
}


int encrypt(string *input, vector<pair<char,char>> *Table){

    for (int i=0; i<(*input).size(); i++){
        if (int((*input).at(i)) ==  (*Table).at(i).first){
            (*input).at(i) = (*Table).at(i).second;
            cout <<("\n")<<(*input);
        }   
    }

    return 0;
}


int createTable(vector<pair<char,char>> *Table){
    int key = 3;
    for (int i=0; i<256; i++){
        (*Table).at(i).first = char(i);
        (*Table).at(i).second= char(i+key);
    }


    return 0;
}

int main (){
    string input;
    pair<char,char> Table;
    vector<pair<char,char>> Pares;

    cout << endl<< endl ;
    getline(cin,input);

    readFile(&input);
    cout << "\n texto:"<< endl << input;
       
    createTable(&Pares);
    
    encrypt(&input, &Pares);
    
    
    return 0;
}
