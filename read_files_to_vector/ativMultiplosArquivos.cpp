#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;





int listFiles(const vector<pair<string, vector<string>>> *AllFiles){

    for (int i =0; i<(*AllFiles).size(); i++){
        cout << "\n\n========= "<<(*AllFiles)[i].first<< " =========\n\n";
        for (int j=0; j<(*AllFiles)[i].second.size() ; j++){
            cout << " [" << j << "] " <<(*AllFiles)[i].second[j] <<endl;
       
        }
    }
    
    cin.get();

    return 0;
};


int keepOnlyFirst(vector<pair<string, vector<string>>> *AllFiles){

    int count=0;
    string input;
    bool firstOccurence = true;
    cout << "----------------------Delete Repeated Words---------------------------- \n";
        
    cout << "   Enter value to be searched and deleted: "<< endl;
    getline(cin,input);    

    for (int i=0;i<(*AllFiles).size();i++){
        cout << endl<<"       File: "<< (*AllFiles)[i].first << ":" <<endl; 
        for (int j=0;j<(*AllFiles)[i].second.size();){
            if ((*AllFiles)[i].second[j] == input){
                if (firstOccurence == true){firstOccurence = false; j++; continue;}; 
                cout << " - " << (*AllFiles)[i].second[j] << " was deleted. 🚮️" <<endl;
                (*AllFiles)[i].second.erase(next((*AllFiles)[i].second.begin(), j));
                
                count++;
            }else{j++;};
        }
    }     
    
    cout << endl<< "[INFO] " << count << " entrys deleted."<<endl;
           
    cin.get();    

    return 0;
};

int removeBySubstring(vector<pair<string, vector<string>>> *AllFiles){

    int count=0;
    string input;
    cout << "----------------------Delete by Substring---------------------------- \n";
        
    cout << "   Enter value to be searched and deleted: "<< endl;
    getline(cin,input);
    
    for (int i=0;i<(*AllFiles).size();i++){
        cout << endl<<"       File: "<< (*AllFiles)[i].first << ":" <<endl; 
        for (int j=0;j<(*AllFiles)[i].second.size();){
            if ((*AllFiles)[i].second[j].find(input) != -1){ // returns -1 if not found
                cout << " - " << (*AllFiles)[i].second[j] << " was deleted. 🚮️" <<endl;
                (*AllFiles)[i].second.erase(next((*AllFiles)[i].second.begin(), j));
                
                count++;
            } else{j++;}; 
        }
    
    };
    
    cout << endl<< "[INFO] " << count << " entrys deleted."<<endl;
           
    cin.get();
    return 0;
}

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
        cout << "------------Menu------------\n\n 1 - Read file \n 2 - List all files \n 3 - Remove by substring \n 4 - Delete repeted words \n 0 - Exit" << endl;
        cout << "Option: ";
        cin>>option;
        cin.ignore();
    
        switch (option){
        
            case '1':
            
                system("clear");
                readFile(&AllFiles);
            
            break;
            
            case '0':
                system("clear");
                return 0;
                break;
                
            case '2':
                system("clear");
                listFiles(&AllFiles);
                break;
        
            case '3':
                system("clear");
                removeBySubstring(&AllFiles);
                break;   
                
            case '4':
                system("clear");
                keepOnlyFirst(&AllFiles);
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
