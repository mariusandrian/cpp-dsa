#include <iostream>
#include <string>

using namespace std;

class HashNode {
private:
  std::string key{};
  std::string value{};
  HashNode *nextNode = nullptr;

public:
  HashNode *next() {
    if (nextNode != nullptr) {
      return nextNode;
    }
    return nullptr;
  };

  std::string getKey() { return key; }

  std::string getValue() { return value; }

  void setKey(std::string k) { key = k; }

  void setValue(std::string v) { value = v; }
};

class UnorderedMap {
private:
  HashNode *arr = new HashNode[8];
  int capacity = 8;

  int getHash(std::string s) {
    // Hash to determine index to put in.
    int charTotalValue = 0;

    for (const char &c : s) {
      std::cout << c << std::endl;
      charTotalValue += c;
    }

    // std::cout << "Char value total is: " << charTotalValue << std::endl;
    int charIndex = charTotalValue % capacity;
    return charIndex;
  }

public:
  void insert(const std::string &key, const std::string &value) {
    // Put in index.
    HashNode n{};
    n.setKey(key);
    n.setValue(value);

    arr[getHash(key)] = n;
    return;
  };

  std::string get(const std::string &key) {
    return arr[getHash(key)].getValue();
  };

  void remove(std::string &key) {
    // TODO
  }
};

int main() {
  UnorderedMap m{};

  m.insert(std::string{"hello"}, std::string{"there"});
  cout << m.get(std::string{"hello"}) << endl;
}

// void print(UnorderedMap &m)
// {
//     for (auto &el : m)
//     {
//         std::cout << el.first() << "->" << el.second() << std::endl;
//     }
// }
