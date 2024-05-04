#ifndef CLASSES_HPP
#define CLASSES_HPP
#include<vector>
#include<string>
#include<utility>
	
using namespace std;


class ConversionTable{


    private:
        vector<pair<char,char>> encrypt_table{256};
        string user_code;
    
        void CreateConvTable(string m_userCode);
        string Hash(string str); 
        
        
    public:
        
        vector<pair<char,char>> GetConversionTable(){return encrypt_table;};
        // only cipher protected methods should access
        
        ConversionTable(const string m_user_code);
        ~ConversionTable();
     
};




class Cipher{

    private:
    
        ConversionTable *conversion_table;
        
        string encrypted_text, input_text;
         
        void Encrypt();
        
        string Decrypt(string m_encrypted_text);
        
    public:
    
        string GetEncryptedText(){
            Encrypt();    
        
            return encrypted_text;
        };
    
        Cipher(const string m_user_code){
            conversion_table = new ConversionTable(m_user_code);
        };
        
        string GetDecryptedText(string m_encrypted_text){
            return Decrypt(m_encrypted_text);
        };
        
        Cipher();
        
        void SetInputText(const string m_input_text){input_text = m_input_text;};
        
        ~Cipher(){delete conversion_table;};    
        // will be called in main to delete both dynamic objects       
        
        
};


#endif
