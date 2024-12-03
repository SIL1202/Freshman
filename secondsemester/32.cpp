#include <iostream>
#include <algorithm>

template <class T>
class Set
{
public:
  Set() : count(0) {}

  Set(const Set<T> &other)
  {
    count = other.count;
    std::copy(other.element, other.element + count, element);
  }

  int add(const T &elem)
  {
    if (!contains(elem))
    {
      if (count < 100)
      {
        element[count++] = elem;
        return 1;
      }
    }
    return 0;
  }

  int add(const Set<T> &other)
  {
    int addedCount = 0;
    for (int i = 0; i < other.count; ++i)
    {
      addedCount += add(other.element[i]);
    }
    return addedCount;
  }

  void display() const
  {
    for (int j = 0; j < count; ++j)
    {
      std::cout << element[j] << " ";
    }
  }

private:
  T element[100];
  int count;

  bool contains(const T &elem) const
  {
    for (int i = 0; i < count; ++i)
    {
      if (element[i] == elem)
      {
        return true;
      }
    }
    return false;
  }
};

