#include <iostream>

#include <initializer_list>

class Vector
{
private:
    int *m_startPtr = new int[8];
    int m_size = 0;
    int m_capacity = 8;

public:
    // TODO: constructor taking in init list.
    // Vector(std::initializer_list<int> &ls)

    void push_back(int element)
    {
        if ((m_size + 1) == m_capacity)
        {
            int newCapacity = m_capacity * 2;
            int *temp = new int[newCapacity];
            std::memcpy(temp, m_startPtr, m_capacity * sizeof(*m_startPtr));
            delete[] (m_startPtr);
            m_startPtr = temp;
            m_capacity = newCapacity;
        }

        m_startPtr[m_size] = element;
        m_size++;
    };

    int at(int pos)
    {
        if (pos > m_size)
        {
            throw std::out_of_range("out of bounds");
        }
        return m_startPtr[pos];
    };

    int size()
    {
        return m_size;
    };

    int capacity()
    {
        return m_capacity;
    }

    void print()
    {
        std::cout << "[";
        for (auto i = 0; i < m_size; ++i)
        {
            std::cout << m_startPtr[i];
            if (i < m_size - 1)
            {
                std::cout << ",";
            }
        }
        std::cout << "]" << std::endl;
    }

    int front()
    {
        return m_startPtr[0];
    };

    int back()
    {
        return m_startPtr[m_size];
    };

    ~Vector()
    {
        delete[] m_startPtr;
    };
};

int main()
{
    Vector *v = new Vector;
    v->push_back(34);
    std::cout << "capacity is: " << v->capacity() << std::endl;
    std::cout << "size is: " << v->size() << std::endl;
    std::cout << v->at(0) << std::endl;

    // Test capacity expansion.
    Vector *v1 = new Vector;
    for (int i = 0; i < 20; ++i)
    {
        v1->push_back(i);
    }
    std::cout << "size is now: " << v1->size() << std::endl;
    std::cout << "capacity is now: " << v1->capacity() << std::endl;
    v1->print();
};