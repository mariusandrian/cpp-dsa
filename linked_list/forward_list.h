#pragma once

#include <string>

struct Node
{
    std::string m_val;
    Node *m_next = nullptr;
};

class ForwardListT
{
public:
    ForwardListT()
        : m_before_first{nullptr}, m_last{nullptr}
    {
    }

    void push_back(const std::string &value);
    Node *begin();
    Node *end();
    const std::string &front();
    const std::string &back();

private:
    Node *m_before_first; // HEAD
    Node *m_last;
};