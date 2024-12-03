#include <iostream>
#include <queue>
#include <stdexcept>
#include <vector>
using namespace std;
/*class Container {
  virtual void push(int) = 0;
  virtual void pop() = 0;
  virtual int top() const = 0;
  virtual bool empty() const = 0;
};*/

class Stack : public Container {
private:
  vector<int> elements;

public:
  void push(int value) override { elements.push_back(value); }
  void pop() override {
    if (empty()) {
      throw out_of_range("Stack is empty cannot pop");
    }
    elements.pop_back();
  }
  int top() const override {
    if (empty()) {
      throw out_of_range("Stack is empty cannot get top");
    }
    return elements.back();
  }
  bool empty() const override { return elements.empty(); }
};

class PriorityQueue : public Container {
private:
  priority_queue<int> elements;

public:
  void push(int value) override { elements.push(value); }
  void pop() override {
    if (empty()) {
      throw out_of_range("Stack is empty cannot pop");
    }
    elements.pop();
  }
  int top() const override {
    if (empty()) {
      throw out_of_range("Stack is empty cannot get top");
    }
    return elements.top();
  }
  bool empty() const override { return elements.empty(); }
};

