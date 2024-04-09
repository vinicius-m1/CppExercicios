#include <iostream>

using namespace std;

int main(){
 
 

 float num[11],media,maior,menor;

    for (int i=1; i<=10; i++){ //começando em 1 por causa dos if's
        
        cout << "Digite o " << i << "° número: \n";
        cin >> num[i];
        media = media + num[i];
    }
        
    media = (media/10);
    menor = num[1];
    maior = num[1];
    
    for (int i=1; i<=10; i++){ //começando em 1 por causa dos if's     
        
        if (num[i]>num[i-1]){
            maior = num[i];
        }
        if (num[i]<num[i-1]){
            menor = num[i];
        }
    }
    
    cout << "Maior número: " << maior << "| Menor número: " << menor << "| Média: " << media << "\n";

 return 0;
};
