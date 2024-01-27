#include <iostream>

#include <initializer_list>

class Vector
{
private:
    int *m_startPtr = new int[0];
    int *m_currPtr = new int[0];
    int m_size = 0;
    int m_capacity = 0;

public:
    // TODO: constructor
    Vector()
        : m_capacity{8}, m_startPtr{new int[8]}
    {
        m_currPtr = m_startPtr;
    }

    // TODO: constructor taking in init list.
    // Vector(std::initializer_list<int> &ls)

    void push_back(int element)
    {
        if ((m_size + 1) == m_capacity)
        {
            int newCapacity = m_capacity * 2;
            int *temp = new int[newCapacity];
            for (int i = 0; i < m_size; ++i)
            {
                temp[i] = m_startPtr[i];
            }
            m_capacity = newCapacity;
        }

        *m_currPtr = element;
        m_currPtr++;
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

    int front(){
        // TODO: get data in front of the vector.
    };

    int back(){
        // TODO: get data at the back of the vector.
    };

    // TODO: destructor
    ~Vector(){};
};

int main()
{
    Vector v{};
    v.push_back(34);
    std::cout << "capacity is: " << v.capacity() << std::endl;
    std::cout << "size is: " << v.size() << std::endl;
    std::cout << v.at(0);
};