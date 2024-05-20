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
    if(m_balance-value+m_limit >= 0)
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

bool ContaCorrente::operator >> (ContaCorrente &account)
{
    if(m_balance >= 0)
    {
        account.Deposit(m_balance);
        m_balance=0;
        return true;
    }
    return false;
}
