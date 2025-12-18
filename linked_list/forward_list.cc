#include "forward_list.h"

void ForwardListT::push_back(const std::string &value)
{
    if (m_before_first == nullptr)
    {
        Node *n = new Node{value};
        m_before_first = (n - 1);
        m_last = n;
        return;
    }
    Node *n = new Node{value};
    m_last->m_next = n;
    m_last = n;
}

const std::string &ForwardListT::front()
{
    return (m_before_first + 1)->m_val;
}

const std::string &ForwardListT::back()
{
    return m_last->m_val;
}

Node *ForwardListT::begin()
{
    return (m_before_first + 1);
}

Node *ForwardListT::end()
{
    return m_last;
}