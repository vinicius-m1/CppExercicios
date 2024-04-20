#include <iostream>
#include <map>




using namespace std;

int main(){


    map <char, int> m1;

    m1['G'] ++;  // If the element 'G' does not exist then it is created and 
             // initialized to zero. A reference to the internal value
             // is returned. so that the ++ operator can be applied.

    // If 'G' did not exist it now exist and is 1.
    // If 'G' had a value of 'n' it now has a value of 'n+1'


    // Create a map of strings to integers
    map<string, int> mp;
 
    // Insert some values into the map
    mp["one"] = 1;
    mp["two"] = 2;
    mp["door"] = 3;
   
 
    // Get an iterator pointing to the first element in the
    // map
    map<string, int>::iterator it = mp.begin();
 
    // Iterate through the map and print the elements
    while (it != mp.end()) {
        cout << "Key: " << (*it).first
             << ", Value: " << it->second << endl;
             
        if (mp.find("door") != mp.end()){
            cout << (*it).first;
            it->first = "too";
            cout << (*it).first;
        }
             
        ++it;
    }
 
    return 0;

    
}
