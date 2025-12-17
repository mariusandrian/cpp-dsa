#pragma once

#include <string>

class HashNode
{
public:
    HashNode(const std::string &key, const std::string &value)
        : m_key{key}, m_value{value}
    {
    }

    HashNode *next()
    {
        if (m_nextNode != nullptr)
        {
            return m_nextNode;
        }
        return nullptr;
    };

    std::string_view getKey() { return m_key; }

    std::string_view getValue() { return m_value; }

    void setNext(HashNode *p)
    {
        m_nextNode = p;
    }

    void setValue(const std::string &value)
    {
        m_value = value;
    }

    HashNode **getNext()
    {
        return &m_nextNode;
    }

private:
    std::string m_key{};
    std::string m_value{};
    HashNode *m_nextNode = nullptr;
};

class UnorderedMapT
{
public:
    void insert(const std::string &key, const std::string &value);

    std::string_view get(const std::string &key);
    void remove(const std::string &key);

private:
    HashNode **arr = new HashNode *[8];
    int capacity = 8;

    int getHash(std::string s)
    {
        // Hash to determine index to put in.
        int charTotalValue = 0;

        for (const char &c : s)
        {
            charTotalValue += c;
        }

        // std::cout << "Char value total is: " << charTotalValue << std::endl;
        int charIndex = charTotalValue % capacity;
        return charIndex;
    }
};