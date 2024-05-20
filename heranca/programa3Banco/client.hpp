#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>

using namespace std;

class Client
{
private:
    string m_name;
    string m_address;
    string m_job;
    float m_income;

public:
    Client(string name,string address,string job,float income) : m_name(name), m_address(address), m_job(job), m_income(income) {};

    string GetName(){return m_name;};
    //getters and setters
    //void update(string name,string address,string job,float income) {}

    string GetInformation();
};

#endif
