#include "account.hpp"

bool ContaCorrente::Deposit(float value)
{
    m_balance += value;
    return true;
}

bool ContaCorrente::Withdraw(float value)
{
    if(m_balance-value >= 0)
    {
        m_balance -= value;
        return true;
    }
    return false;
}

bool ContaEspecial::Withdraw(float value)
{
    if(((m_balance+m_limit)-value) >= 0)
    {
        m_balance -= value;
        return true;
    }
    return false;
}

bool ContaCorrente::Transfer(ContaCorrente &account, float value)
{
    if(m_balance-value >= 0)
    {
        m_balance -= value;
        account.Deposit(value);
        return true;
    }
    return false;
}

string ContaCorrente::GetClientName()
{
    std::string str = (m_client->GetName() + " R$: " + std::to_string(m_balance) );
    //return m_client->GetInformation();
    return str;
}

string ContaCorrente::GetClientFullInfo()
{

    return (m_client->GetInformation() + " balance: " + std::to_string(m_balance));

}

bool ContaEspecial::Transfer(ContaCorrente &account, float value)
{
    if(m_balance-value+m_limit >= 0)
    {
        m_balance -= value;
        account.Deposit(value);
        return true;
    }
    return false;
}

