#include <iostream>
#include <string.h>
using namespace std;

int main(){
    const string alphabet = "xquQWEdBbfoZwgjenzcsAPrISUhNvHiGJtaKLykmlMDOCYXRpTVF.,;ãõÇ}{2301)(45é6 987!ç@#$%"; 
    int  key = (4);
    string opcao;
    
    cout << "[1] Criptografar | [2] Descriptografar" << endl;
    getline(cin, opcao);
    cout << "Endereço variavel opcao:" << &opcao << endl;
    
    if (opcao == "2"){key=(key*-1);};
    
    string text;
    cout << "Texto: ";
    getline(cin, text);

    string final = text;

    for (int i=0;i<text.size();i++){
        for (int j=0;j<alphabet.size();j++){
            if (text[i] == alphabet[j]){
                final[i] = alphabet[j+key];
                cout << "Text changed: " << final << endl;
            }; 
        };
    };
    return 0;
};


