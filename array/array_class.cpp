#include <iostream>

using namespace std;

class MyArray
{
private:
  int *m_start = nullptr;
  int currIndex = 0;
  int capacity = 0;

public:
  MyArray(size_t p_capacity)
  {
    m_start = new int[p_capacity];
    capacity = p_capacity;
  }

  int append(int el)
  {
    if (currIndex >= capacity)
    {
      throw std::out_of_range("out of bounds");
    }
    m_start[currIndex] = el;
    ++currIndex;
  }

  int &operator[](int i)
  {
    if (currIndex >= capacity)
    {
      throw std::out_of_range("out of bounds");
    }
    return *(m_start + i);
  }
};

int main()
{
  MyArray *arr = new MyArray(5);
  auto a = (*arr)[0];
  for (int i = 0; i < 5; ++i)
    (*arr)[i] = i;

  return 0;
}
