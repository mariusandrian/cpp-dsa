#include <array>

class MyArray
{
private:
  int *m_start = nullptr;
  int capacity = 0;

public:
  MyArray(size_t p_capacity)
  {
    m_start = new int[p_capacity];
    capacity = p_capacity;
  }
};

int main()
{
  MyArray *arr = new MyArray(5);

  return 0;
}
