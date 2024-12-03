#include <iostream>
using namespace std;

template <class T> class LinkedList {
public:
  class Node {
  public:
    Node() : next(nullptr), data(0) {}
    Node(T d) : next(nullptr), data(d) {}
    Node(Node *n) : next(n), data(0) {}
    Node(Node *n, T d) : next(n), data(d) {}
    T data;
    Node *next;
  };

  LinkedList() : head(nullptr) {}
  ~LinkedList() {
    Node *current = head;
    while (current != nullptr) {
      Node *nextNode = current->next;
      delete current;
      current = nextNode;
    }
  }

  bool addFromHead(T d) {
    Node *newNode = new Node(d);
    newNode->next = head;
    head = newNode;
    return true;
  }

  bool addFromTail(T d) {
    Node *newNode = new Node(d);
    if (head == nullptr) {
      head = newNode;
    } else {
      Node *current = head;
      while (current->next != nullptr) {
        current = current->next;
      }
      current->next = newNode;
    }
    return true;
  }

  bool removeFromHead() {
    if (head == nullptr)
      return false;
    Node *temp = head;
    head = head->next;
    delete temp;
    return true;
  }

  bool removeFromTail() {
    if (head == nullptr)
      return false;
    if (head->next == nullptr) {
      delete head;
      head = nullptr;
      return true;
    }
    Node *current = head;
    while (current->next->next != nullptr) {
      current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    return true;
  }

  friend ostream &operator<<(ostream &o, LinkedList *l) {
    Node *current = l->head;
    while (current != nullptr) {
      o << current->data << " ";
      current = current->next;
    }
    return o;
  }

  size_t getSize() const {
    size_t size = 0;
    Node *current = head;
    while (current != nullptr) {
      size++;
      current = current->next;
    }
    return size;
  }

  bool searchData(T d) const { // change the return type to bool so that it can
                               // be used in Set class
    Node *current = head;
    while (current != nullptr) {
      if (current->data == d)
        return true;
      current = current->next;
    }
    return false;
  }

  T operator[](size_t i) const {
    Node *current = head;
    size_t index = 0;
    while (current != nullptr && index < i) {
      current = current->next;
      index++;
    }
    if (current != nullptr)
      return current->data;
    throw out_of_range("Index out of range");
  }

protected:
  Node *head;
};

template <class T> class Set : private LinkedList<T> {
public:
  Set() : LinkedList<T>() {}
  ~Set() {}

  bool addElement(T d) {
    if (this->searchData(d))
      return false; // Element already exists
    this->addFromTail(d);
    return true;
  }

  friend ostream &operator<<(ostream &o, Set<T> *s) {
    typename LinkedList<T>::Node *current =
        s->head; // Since Node is a dependent name (it depends on the template
                 // parameter T), we need to use typename to tell the compiler
                 // that LinkedList<T>::Node is a type.
    o << "{";
    bool first = true;
    while (current != nullptr) {
      if (!first)
        o << ", ";
      o << current->data;
      first = false;
      current = current->next;
    }
    o << "}" << endl;
    return o;
  }

  Set<T> *operator+(Set<T> *s) {
    Set<T> *result = new Set<T>();
    typename LinkedList<T>::Node *current = this->head;
    while (current != nullptr) {
      result->addElement(current->data);
      current = current->next;
    }
    current = s->head;
    while (current != nullptr) {
      result->addElement(current->data);
      current = current->next;
    }
    return result;
  }

  Set<T> *operator-(Set<T> *s) {
    Set<T> *result = new Set<T>();
    typename LinkedList<T>::Node *current = this->head;
    while (current != nullptr) {
      if (!s->searchData(current->data)) {
        result->addElement(current->data);
      }
      current = current->next;
    }
    return result;
  }

  Set<T> *operator*(Set<T> *s) {
    Set<T> *result = new Set<T>();
    typename LinkedList<T>::Node *current = this->head;
    while (current != nullptr) {
      if (s->searchData(current->data)) {
        result->addElement(current->data);
      }
      current = current->next;
    }
    return result;
  }
};
