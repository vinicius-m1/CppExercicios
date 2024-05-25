#include <iostream>
#include <vector>
#include <string>
#include "classes.hpp"
using namespace std;

int main(){

    new string test = "test";
    new ChristmasCard c1(test);
    new ChristmasCard c2("pedro");
    new ValentinesCard c3("felipe");
    new ValentinesCard c4("cleber");
    new BirthdayCard c5("rafael");
    
    vector<Cards*> cards_list;
    cards_list.push_back(c1);
    cards_list.push_back(c2);
    cards_list.push_back(c3);
    cards_list.push_back(c4);
    cards_list.push_back(c5);
    
    for (int i =0; i<cards_list.size();i++){
        
        cards_list.at(i).ShowMessage();
        delete (cards_list.at(i));
    };

    return 0;
};
