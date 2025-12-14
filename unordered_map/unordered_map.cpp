#include <iostream>
#include <string>
#include <string_view>

class HashNode
{
private:
  std::string m_key{};
  std::string m_value{};
  HashNode *m_nextNode = nullptr;

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
};

class UnorderedMap
{
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

public:
  void insert(const std::string &key, const std::string &value)
  {
    if (key.empty())
    {
      // ? what is better to do?
      throw std::invalid_argument("key must not be empty");
    }

    HashNode *n = new HashNode{key, value};

    arr[getHash(key)] = n;

    return;
  };

  std::string_view get(const std::string &key)
  {
    std::cout << "get: " << arr[getHash(key)]->getValue() << '\n';
    return arr[getHash(key)]->getValue();
  };

  void remove(const std::string &key)
  {
    if (key.empty())
    {
      // ? what is better to do?
      throw std::invalid_argument("key must not be empty");
    }

    //   if ((*arr)[getHash(key)].getKey().empty())
    //   {
    //     return;
    //   }
    //   else
    //   {
    //     arr[getHash(key)]
    //   }

    //   if (arr[getHash(key)])
  }
};

int main()
{
  UnorderedMap m{};

  m.insert("hello", "there");
  // m.get("hello");
  std::cout << m.get("hello") << std::endl;
}

// void print(UnorderedMap &m)
// {
//     for (auto &el : m)
//     {
//         std::cout << el.first() << "->" << el.second() << std::endl;
//     }
// }
