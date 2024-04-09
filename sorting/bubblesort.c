#include <iostream>

#define size 10

using namespace std;

int main (){

int num[14] = {11,2,75,34,63,23,32,-4,3,4};
int temp;
for (int i=1; i<size; i++){
    for (int j=0; j<size-1; j++){
        
        if (num[j] > num[j+1]){
        
            temp = num[j];
            num[j] = num[j+1];
            num[j+1] = temp;
            
        }
            
            for (int k=0;k<size; k++){cout << " " << num[k];};
        cout << endl;
                    
    };
};


return 0;
};
