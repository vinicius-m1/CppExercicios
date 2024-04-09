#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;





int listFiles(const vector<pair<string, vector<string>>> *AllFiles){

    for (int i; i<(*AllFiles).size(); i++){
        cout << (*AllFiles)[i].first << endl;
        for (int j; j<((*AllFiles)[i].second).size() ; j++){
            cout<< ((*AllFiles)[i].second)[j] <<endl;
       
        }
    }
    cout << "bruh";
    cin.get();

    return 0;
};



int readFile(vector<pair<string, vector<string>>> *AllFiles){

    pair<string,vector<string>> IndividualFile;
    vector<string> filedata;
    string filename,line;
    
    cout << "-------------Load-----------------" <<endl;
    system("ls");
    cout <<endl<<("Enter file name: ");
    getline(cin,filename);
    
    ifstream datafile(filename);
    
    if (datafile.is_open() == true){
    
        while (getline(datafile,line))
        {
            filedata.push_back(line);
        };
        datafile.close();   
        
        IndividualFile.first = filename;
        IndividualFile.second = filedata;
        (*AllFiles).push_back(IndividualFile);
        cout << endl <<("File Loaded.");
    } 
    else {
        cout << "Invalid Filename!";
        cin.get();
        return 0;
    }       
    
    cin.get();

    return 0;
}


int main(){

    vector<pair<string, vector<string>>> AllFiles;

    char option;
    while (true){
        system ("clear");
        cout << "------------Menu------------\n\n 1 - Read file \n 2 - List all files \n 0 - Exit" << endl;
        cout << "Option: ";
        cin>>option;
        cin.ignore();
    
        switch (option){
        
            case '1':
            
                system("clear");
                readFile(&AllFiles);
            
            break;
            
            case '0':
            
                return 0;
                break;
                
            case '2':
                system("clear");
                listFiles(&AllFiles);
                break;
        
            default:
            
                system("clear");
                cout << "Invalid option!"<<endl;
                cin.get();
                break;
        }
    };
    
    


    return 0;
}
