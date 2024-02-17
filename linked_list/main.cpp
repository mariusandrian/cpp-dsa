#include <iostream>

using namespace std;

struct Node
{
    Node(int pValue): value(pValue) {}
    int value;    
    Node* next;
};

class LinkedList
{
private:
    Node* head = nullptr;
    Node* last = nullptr;
    
public:
    Node* push_back(int value)
    {
        Node* n = new Node(value);
        if (head == nullptr)
        {
           head = n;
           last = n;
        } else {
           last->next = n; 
           last = last->next;
        }
        return n;
    }

    // const function means that this function cannot change the object.
    Node* front() const
    {
        //TODO
        return nullptr;
    }

    void print() const
    {
        Node* curr = head;
        while(curr != nullptr)
        {
            cout << curr->value << endl;  
            curr = curr->next;
        }
    }

    ~LinkedList()
        Node* curr = head;
        while(curr != nullptr)
        {
            Node* temp = curr->next;
            delete curr;
            curr = temp; 
        }
    }
};

int main()
{
    LinkedList* ll = new LinkedList();
    ll->push_back(1);  
    ll->push_back(2);  
    ll->push_back(3);  
    ll->push_back(4);  
    
    ll->print();
    delete ll;

    return 0;
}
