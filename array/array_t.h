#pragma once

#include <cstddef>

template <class T, std::size_t N>
struct ArrayT
{
    T m_arr[N];

    T at(size_t idx)
    {
        if (idx > (N - 1))
            throw std::out_of_range("index out of range");
        return m_arr[idx];
    }

    std::size_t size()
    {
        return N;
    }

    T front()
    {
        return m_arr[0];
    }

    T back()
    {
        return m_arr[N - 1];
    }

    T *data()
    {
        return m_arr;
    }

    T *begin()
    {
        return m_arr;
    }

    T *end()
    {
        return m_arr + N;
    }

    T &operator[](std::size_t idx)
    {
        if (idx > (N - 1))
            throw std::out_of_range("index out of range");
        return m_arr[idx];
    }

    void fill(const T &value)
    {
        for (int i = 0; i < N; ++i)
        {
            m_arr[i] = value;
        }
        return;
    }
};