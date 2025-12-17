#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>

#include "umap.h"

void UnorderedMapT::insert(const std::string &key, const std::string &value)
{
  if (key.empty())
  {
    // ? what is better to do?
    throw std::invalid_argument("key must not be empty");
  }

  HashNode *n = new HashNode{key, value};

  int hash = getHash(key);
  if (arr[hash] == nullptr)
  {
    arr[hash] = n;
    return;
  }

  HashNode *curr = arr[hash];
  if (curr->getKey() == key)
  {
    curr->setValue(value);
    return;
  }
  while (curr->next() != nullptr)
  {
    if (curr->getKey() == key)
    {
      curr->setValue(value);
      return;
    }
    curr = curr->next();
  }

  curr->setNext(n);

  return;
};

std::string_view UnorderedMapT::get(const std::string &key)
{
  // std::cout << "get: " << arr[getHash(key)]->getValue() << '\n';
  auto node = arr[getHash(key)];
  if (node == nullptr)
    throw std::out_of_range("key not found");
  return arr[getHash(key)]->getValue();
};

void UnorderedMapT::remove(const std::string &key)
{
  if (key.empty())
  {
    // ? what is better to do?
    throw std::invalid_argument("key must not be empty");
  }

  HashNode **curr = &(arr[getHash(key)]);
  if (*curr == nullptr)
  {
    return;
  }

  HashNode **prev = curr;
  curr = (*curr)->getNext();
  while (*curr != nullptr && (*curr)->getKey() != key)
  {
    prev = curr;
    curr = (*curr)->getNext();
  }

  (*prev) = (*curr);
  delete *curr;

  return;
}

// int main()
// {
//   UnorderedMapT m{};

//   m.insert("hello", "there");
//   // m.get("hello");
//   std::cout << m.get("hello") << std::endl;
// }

// void print(UnorderedMap &m)
// {
//     for (auto &el : m)
//     {
//         std::cout << el.first() << "->" << el.second() << std::endl;
//     }
// }
