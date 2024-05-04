#include "classes.hpp"
#include <algorithm>
#include<iostream>
#include <fstream>
// Cipher Implementations



string Cipher::Decrypt(string m_encrypted_text){

    vector<pair<char,char>> m_conversion_table = conversion_table->GetConversionTable();
    string output;
    for(size_t i=0; i<m_encrypted_text.size(); i++)
    {
        char ch = m_encrypted_text.at(i);
        for(size_t j=0; j<m_conversion_table.size(); j++)
        {
            if(ch == m_conversion_table.at(j).second)
            {
                output += m_conversion_table.at(j).first;
                break;
            }
        }
    }
    return output;
};


void Cipher::Encrypt(){

    string output;
    vector<pair<char,char>> m_conversion_table = conversion_table->GetConversionTable();
    for(size_t i=0; i<input_text.size(); i++){
        char ch = input_text.at(i);
        output += m_conversion_table.at(ch).second;
    };
    
    encrypted_text = output;
    
    ofstream datafile("data.txt");
    datafile << output;
    datafile.close();
    
};

// CoversionTable Implementations


ConversionTable::ConversionTable(const string m_user_code){

    user_code = ConversionTable::Hash(m_user_code);
    cout << "hash done: "<< user_code<<endl;
    int j=1;
    for(size_t i=0; i<256; i++){
        j=j*-1;
        encrypt_table.at(i).first = i;
        encrypt_table.at(i).second = j*((i + user_code.at(i%user_code.size()))%255);
        
        //cout << "1 - " << encrypt_table.at(i).first << "    2 - "<< encrypt_table.at(i).second<<endl;
        
    };
    cout << "done";
};

string ConversionTable::Hash(string str){

    // salting
    string salt = str;
    sort(salt.begin(),salt.end());
    str = (str + salt + "jP30iWe");
    // djb2 hash function
    unsigned long hash = 5381;
    for (char c : str) {
        hash = ((hash << 5) + hash) + c;
    }
    return to_string(hash);
    
};
