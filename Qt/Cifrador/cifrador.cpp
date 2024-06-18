#include "cifrador.hpp"

void Cifrador::CreateTable(size_t key)
{
    vector<pair<char,char>> table(256);

    for(size_t i=0; i<256; i++)
    {
        table.at(i).first = i;
        table.at(i).second = i+key;
    }

    m_table = table;
}

string Cifrador::Encrypt(string input)
{
    string output;
    for(size_t i=0; i<input.size(); i++)
    {
        char ch = input.at(i);
        output += m_table.at(ch).second;
    }
    return output;
}


string Cifrador::Decrypt(string input)
{
    string output;
    for(size_t i=0; i<input.size(); i++)
    {
        char ch = input.at(i);
        for(size_t j=0; j<m_table.size(); j++)
        {
            if(ch == m_table.at(j).second)
            {
                output += m_table.at(j).first;
                break;
            }
        }
    }
    return output;
}
