
#include <iostream>
#include <algorithm> // for std::swap

using namespace std;

// Sorting function template
template <typename T>
T *sort(T *array, int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (array[j] > array[j + 1])
      {
        std::swap(array[j], array[j + 1]);
      }
    }
  }
  return array;
}

/*int main()
{
  int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int n = 10;
  sort(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}*/

