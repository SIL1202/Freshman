#include <iostream>
using namespace std;

class LinkedList
{
public:
  class Node
  {
  public:
    Node() : next(nullptr), data(0) {}
    Node(int d) : next(nullptr), data(d) {}
    Node(Node *n) : next(n), data(0) {}
    Node(Node *n, int d) : next(n), data(d) {}
    int data;
    Node *next;
  };
  LinkedList() : head(nullptr) {}
  ~LinkedList()
  {
    while (head != nullptr)
    {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }
  bool addFromHead(int d)
  {
    Node *newNode = new Node(d);
    newNode->next = head;
    head = newNode;
    return true;
  }
  bool addFromTail(int d)
  {
    Node *newNode = new Node(d);
    if (head == nullptr)
      head = newNode;
    else
    {
      Node *current = head;
      while (current->next != nullptr)
      {
        current = current->next;
      }
      current->next = newNode;
    }
    return true;
  }
  bool removeFromHead()
  {
    if (head == nullptr)
      return false;
    Node *temp = head;
    head = head->next;
    delete temp;
    return true;
  }
  bool removeFromTail()
  {
    if (head == nullptr)
      return false;
    if (head->next == nullptr)
    {
      delete head;
      head = nullptr;
    }
    else
    {
      Node *current = head;
      while (current->next->next != nullptr)
      {
        current = current->next;
      }
      delete current->next;
      current->next = nullptr;
    }
    return true;
  }
  friend ostream &operator<<(ostream &o, LinkedList *l)
  {
    o << "{";
    Node *current = l->head;
    while (current != nullptr)
    {
      o << current->data;
      if (current->next != nullptr)
        o << ", ";
      current = current->next;
    }
    o << "}" << "\n";
    return o;
  }
  size_t getSize() const
  {
    size_t size = 0;
    Node *current = head;
    while (current != nullptr)
    {
      size++;
      current = current->next;
    }
    return size;
  }

private:
  Node *head;
};

/*int main()
{
  LinkedList ll;
  ll.addFromHead(45);
  ll.addFromHead(34);
  ll.addFromTail(87);
  ll.addFromTail(66);
  ll.addFromTail(54);
  ll.addFromTail(69);
  ll.addFromTail(34);
  ll.removeFromHead();
  ll.removeFromHead();
  ll.removeFromTail();
  ll.removeFromTail();
  cout << &ll;
  return 0;
}
*/
