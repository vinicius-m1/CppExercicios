#include "client.hpp"
#include <sstream>

string Client::GetInformation()
{
    stringstream stt;
    stt << "Client name: " << m_name << " Job: " << m_job << " Income: " << m_income;

    return stt.str();
}

