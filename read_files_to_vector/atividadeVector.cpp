// Vinicius Magnus Barbosa - 23201046
// 04/24 UFSC - Eng Computação - Ling Prog II

#include <iostream>
#include<unistd.h>
#include <vector>
#include <fstream>
using namespace std;

// at start tries to load only the default filename "data.txt", to load custom files use the menu option. 
// "data.txt" is the filename used to store the strings.
// each individual string is separated by std::endl, both in reads and writes

int menu (){
    char option;

    cout << "-------------------------------------------------- \n";
    cout << "                 String Store V.0 \n 1 - Insert string \n 2 - Print index and string \n 3 - Search string (literal) \n 4 - Search substrings \n 5 - Remove string (by index) \n 6 - Remove by substring (all occurences) \n 7 - Input from external file \n 8 - Empty vector \n 0 - Quit \n";

    cout << "-------------------------------------------------- \n";    
    cin.clear();
    cin >> (option);  
    cin.ignore();
    
    return (option);
};


int emptyVector(vector<string> *wordsVector){
    char confirmation;
   
    cout << "-------------------Empty Vector-----------------"<< endl;
    
    if ((*wordsVector).empty()){
        cout << endl << "Invalid! Vector already empty." << endl;
        cout << "----------------------------------------------------------------- \n";  
        cin.get();
        return 1;
    };
    
    cout << "This action will delete all data in the vector, confirm? (y/n):";
    cin >> (confirmation);
    cin.ignore();
    
    if (toupper(confirmation) == 'Y'){
        (*wordsVector).clear();
        cout << endl<<"[INFO] All entrys were deleted.";
        cin.get();
    };
    

    return 0;
}


int writeExternalFile(const vector<string> *wordsVector){

    if ((*wordsVector).empty()){
        char confirmation;
        cout << "[Warning] Vector is empty, save anyway? (y/n)"<<endl;
        cin >> confirmation;
        cin.ignore();
        if (toupper(confirmation) == 'N'){return 0;};
    };
    cout << "[INFO] Saving File..."<<endl;
    ofstream datafile("data.txt");
    
    for (int i=0;i<(*wordsVector).size();i++){
        datafile << (*wordsVector)[i] << endl; 
    };
    datafile.close();
    cout << "[INFO] Saved."<<endl;

    return 0;
}


int enterDummyValues(vector<string> *wordsVector){
    

    (*wordsVector).push_back("bola");
    (*wordsVector).push_back("carpete azul");
    (*wordsVector).push_back("rapido cinza");
    (*wordsVector).push_back("atrasado - constante");
    (*wordsVector).push_back("inverso 大象");
    (*wordsVector).push_back("Chile, Equador");


    return 0;
}


int readExternalFile(vector<string> *wordsVector, int mode){


    string filename,line;
    char confirmation;

    if (mode == 1){ //if called by start up
    
        filename = ("data.txt"); //default
        ifstream existCheck(filename);
        if(existCheck.is_open()){
            cout << "Saved data detected, load file? (y/n) ";
            cin >> (confirmation);
            cin.ignore();
            existCheck.close();
            if (toupper(confirmation) != 'Y'){return 0;};            
        } else {return 0;};
                   
    };

    if (mode == 0){ //called by user
        cout << "-----------------------Load File---------------------\n\n";
        system("ls");
        cout << endl << "Choose file: "; 
        getline(cin,filename);
    };
    
    ifstream datafile(filename); //doesnt check for file type
    
    if (datafile.is_open()){
    
        while (getline(datafile,line))
        {
            (*wordsVector).push_back(line);
        };
        datafile.close();   
        cout <<"\n[INFO] File successfully loaded.\n";
        cin.get();
        
    } else {
    
        cout << endl<< "[Error] Invalid file name!" << endl;
        cin.get();
        return 1;
    };


    return 0;
};


int searchStringLiteral(const vector<string> *wordsVector){
    int found =0;
    string input;
    
    cout << "----------------------Literal String Search---------------------------- \n";
    
    if ((*wordsVector).empty()){
        cout << endl << "Invalid! Vector empty." << endl;
        cout << "----------------------------------------------------------------- \n";  
        cin.get();
        return 1;
    };
    
    cout << endl <<  "Enter value to be searched: "<< endl;
    getline(cin,input);
        
    for (int i=0; i<(*wordsVector).size(); i++){
        if ((*wordsVector)[i] == input){
            cout << "Found at: [" << i << "] "<< (*wordsVector)[i] << endl;
            found++;
        }
    }
    
    cout << "\n\n[INFO] "<< found << " matching entrys found." <<endl;
    cout << "----------------------------------------------------------------------- \n";
    cin.get();
    return 0;
}




int searchSubstring(const vector<string> *wordsVector){
    int found = 0;
    string input;
    cout << "----------------------Substring Search---------------------------- \n";
    
    if ((*wordsVector).empty()){
        cout << endl << "Invalid! Vector empty." << endl;
        cout << "----------------------------------------------------------------- \n";  
        cin.get();
        return 1;
    };
        
    cout << "   Enter value to be searched: "<< endl;
    
    getline(cin,input);
       
    for (int i=0; i<(*wordsVector).size(); i++){
    
        if ((*wordsVector)[i].find(input) != -1){ // returns -1 if not found
            cout << "Value found at: ["<< i <<"] " << (*wordsVector)[i]<< endl;
            found++;       
            }
    };
    
    cout << "\n\n[INFO] "<< found << " matching entrys found." <<endl;
    cout << "\n\n\n---------------------------------------------------------------- \n";
    cin.get();
    

    return 0;
};


int deleteBySubstring(vector<string> *wordsVector){

    int found =0, last=0;
    string input;
    cout << "----------------------Delete by Substring---------------------------- \n";
    
    if ((*wordsVector).empty()){
        cout << endl << "Invalid! Vector empty." << endl;
        cout << "----------------------------------------------------------------- \n";  
        cin.get();
        return 1;
    };
        
    cout << "   Enter value to be searched and deleted: "<< endl;
    
    getline(cin,input);
    
    for (int i=0; i<(*wordsVector).size(); i++){
    
        if ((*wordsVector)[i].find(input) != -1){ // returns -1 if not found
            cout << "[INFO] Value found in: ["<< i <<"] " << (*wordsVector)[i]<< endl;           
            found++;       
            }
    };
        
    if (found == 0){
        cout << "[INFO] There were no matching values found."<< endl;
        cin.get();
        return 0;
        
    cout << endl << "[INFO] " << found << " entrys to be deleted." << endl;    
    };
    
    
    cout << "\n\n\n---------------------------------------------------------------- \n";
    
    cout << "These values will be deleted, is that ok? (y/n) "<< endl;
    char confirmation;
    cin >> confirmation;
    cin.ignore();
    
    int initial_size = (*wordsVector).size();
    
    if (toupper(confirmation) != 'N'){
         
        for(int i=0; i<initial_size; ++i, ++last)
        {
            while((*wordsVector)[i].find(input) != -1)
            ++i;
            if(i >= initial_size) break;
            
            (*wordsVector)[last] = (*wordsVector)[i];
              
        }

        (*wordsVector).resize(last);   // much faster than erase
    
//        for (int i=0; i<(*wordsVector).size();){
//    
//            if ((*wordsVector)[i].find(index) != -1){ // returns -1 if not found
//                
//                (*wordsVector).erase(next((*wordsVector).begin(), i));              
//                    
//            } else{i++;};
//        };
        cout << endl << (initial_size - last) << " Entrys were deleted."<< endl;
        cin.get();
     };       
     
    return 0;
}

int deleteByIndex(vector<string> *wordsVector){

    int index;

    cout << "----------------------Delete by Index---------------------------- \n";
    
    if ((*wordsVector).empty()){
        cout << endl << "Invalid! Vector empty." << endl;
        cout << "----------------------------------------------------------------- \n";  
        cin.get();
        return 1;
    };
    
    for (int i=0;i<(*wordsVector).size(); i++){
        cout << "[" << i<< "] "<< (*wordsVector)[i] << endl;
    };
    
    cout << "----------------------------------------------------------------- \n";      
    cout << "  Index to be deleted: ";
    
    
    cin >> (index);
    cin.ignore();
    
    if (index > (*wordsVector).size() || index < 0){
        cout << endl << "Invalid index value." << endl;
        cin.get();
        return 1;
    };
    
    (*wordsVector).erase(next((*wordsVector).begin(), index));
    cout << endl << "Deleted. " << endl;
    cin.get();
    
    return 0;
};



int printIndexString(const vector<string> *wordsVector){
    
    cout << "----------------------Index and Value---------------------------- \n";
    
    if ((*wordsVector).empty()){
        cout << endl << "[INFO] Vector empty." << endl;
        cout << "----------------------------------------------------------------- \n";
        cin.get();
        return 1;
    };    
    
    //int i;
    //for (auto element : (*wordsVector)){
    //    i++;
    //    cout << "["<< i << "] " <<  element <<endl;
    //}     same speed
    
        
    for (int i=0;i<(*wordsVector).size(); i++){
        cout << "[" << i<< "] "<< (*wordsVector)[i] << endl;
        
    }
    cout << endl << (*wordsVector).size() <<" entrys in vector.  \n";
    cin.get();
    cout << "----------------------------------------------------------------- \n";


    return 0;
};



int insertString(vector<string> *wordsVector){

    string var;
    
    cout << "---------------------Insert String------------------------- \n";
    
    cout << "\n Please insert the string to be included in the vector: ";
    getline(cin,var);
    
    (*wordsVector).push_back(var); 
    cout  << endl << "  [INFO] Value added: "<< (*wordsVector).back() << endl;
    
    cout << "----------------------------------------------------------- \n";
    cin.get();
    return 0;

};

int main (){

    vector<string> words;
    system("clear");
    readExternalFile(&words,1);
    do {
        system("clear");
        char option = menu();
        
        
        switch (option) {
        
            case ('1'): 
                system("clear");
                insertString(&words);
                break;
            
            case ('2'):
                system("clear");
                printIndexString(&words);    
                break;
            
            case ('3'): 
                system("clear");
                searchStringLiteral(&words);
                break;
            
            case ('4'):
                system("clear");
                searchSubstring(&words);
                break;
            
            case ('5'):
                system("clear");
                deleteByIndex(&words);
                break;
                
            case ('6'):
                system("clear");
                deleteBySubstring(&words);
                break;
            
            case ('7'): 
                system("clear");
                readExternalFile(&words,0);
                break;
                
            case ('8'):
                system("clear");
                emptyVector(&words);
                break;
                
            case ('9'):
                // debug only
                enterDummyValues(&words);
                break;
            
            case ('0'):
                system("clear");
                writeExternalFile(&words);
                return 0; // close program bcs main func
                break;
            
            default:
                system("clear");
                cout << "\n Invalid option entered! \n";
                cin.get();              
                break; 
        }

    }while (true);  

    return 0;
};
