#include<iostream>
#include "classes.hpp"
#include <vector>
#include <string>

using namespace std;

char menu();
int scheduleTask();
int pickTask1();
int pickTask2();
int printPending();

// -------------------------------------------------------------------------------------------------


int printPending(const vector<size_t> *tasks){

    cout << "=========Pending Tasks========"<<endl;
    
    cout<< "vec ID | task ID"<<endl;
    for (size_t i=0; i<tasks->size(); i++){
        cout << "["<<i<<"]      ["<<tasks->at(i)<<"]"<<endl;
    };
    
    cin.get();
    return 0;
};



int scheduleTask(vector<size_t> *tasks){

    cout << "=========Schedule Task========"<<endl;
    
    cout<< "==============================\nTask ID: ";
    int input;
    cin.clear();
    cin >> input;
    cin.ignore();
    
    // test for duplication
    tasks->push_back(input);
    cout << endl << "[INFO] Value added."<<endl;
    
    cin.get();
    return 0;
};


int pickTask2(vector<size_t> *tasks){

    cout << "=========Pick Task = Policy 2========"<<endl;
    int status;
    cout <<endl<< "[INFO] Processing using policy 2.";
    
    PolicyTwo processing_task(tasks); // endereco original ou do vetor?
    status = processing_task.Process();
    
    if (status == 1){
        cout <<endl<<"Error Processing!";
        cin.get();
        return 1;
    };
    cout <<endl<<"[INFO] Done Processing.";
    
    cin.get();
    return 0;
};


int pickTask1(vector<size_t> *tasks){

    cout << "=========Pick Task = Policy 1========"<<endl;
    int status;
    cout<< endl<< "[INFO] Processing using policy 1.";
    
    PolicyOne processing_task(tasks); // endereco original ou do vetor?
    status = processing_task.Process();
    
    if (status == 1){
        cout <<endl<<"Error Processing!";
        cin.get();
        return 1;
    };
    cout <<endl<<"[INFO] Done Processing.";
    
    cin.get();
    return 0;
};



char menu(){
    system("clear");
    cout << "========Menu======= \n 1 - Schedule a task to process \n 2 - Pick up a task to process using policy 1 \n 3 - Pick up a task to process using policy 2 \n 4 - Print pending tasks \n 5 - Exit " <<endl;
    cout << "===================\nOption: ";

    char input;
    cin.clear();
    cin >> input;
    cin.ignore();
    
    return toupper(input);
};



int main()
{

    vector<size_t> tasks;
     

    while (true){
        system("clear");
        
        switch(menu()){
        
            case('5'):
                system("clear");
                return 0;
                break;
                
            case('1'):
                system("clear");
                scheduleTask(&tasks);
                break;
                
            case('2'):
                system("clear");
                pickTask1(&tasks);
                break;

            case('3'):
                system("clear");
                pickTask2(&tasks);
                break;
                
            case('4'):
                system("clear");
                printPending(&tasks);
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


