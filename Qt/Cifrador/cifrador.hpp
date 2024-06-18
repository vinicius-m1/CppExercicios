#ifndef CIFRADOR_HPP
#define CIFRADOR_HPP

#include <iostream>
#include <vector>
using namespace std;

class Cifrador
{
private:
    vector<pair<char,char>> m_table;

public:
    Cifrador() {};
    ~Cifrador() {};

    void CreateTable(size_t v);
    string Encrypt(string input);
    string Decrypt(string input);

};

#endif // CIFRADOR_HPP
