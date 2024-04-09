#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

 float media,maior,menor;
 float *num = new float[argc+1]; // O.S was passing filename as arg, that is the reason for the +1 and -1's
 
    for (int i=0; i<argc-1; i++){ 
         
        num[i] = atof(argv[i+1]); // converting(atof) char to float
        media = media + num[i];
        //cout << "Received values: " << num[i] << endl;
    };
    
    media = (media/10);
    menor = num[0];
    maior = num[0];
    
    for (int i=0; i<argc-1; i++){     
        
        if ((num[i]>num[i-1]) && (i!=0)){
            maior = num[i];
        }
        if ((num[i]<num[i-1]) && (i!=0)){
            menor = num[i];
        }
    }
    delete [] num;
    
    cout << "Maior número: " << maior << " | Menor número: " << menor << " | Média: " << media << "\n";

 return 0;
};






