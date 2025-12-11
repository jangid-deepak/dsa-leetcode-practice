#include <iostream>
#include <vector>

using namespace std;

void consoleArray(vector<int> &arr)
{
  for (int num : arr)
  {
    cout << num << ' ';
  }
  cout << endl;
}

void bubbleSort(vector<int> &arr)
{
  int size = arr.size();
  for (int i = 0; i < size; i++)
  {
    cout << "index i: "<< i << endl;
    bool swapped = false;
    for (int j = 0; j < size-i-1; j++)
    {
      if (arr[j] < arr[j+1])
      {
        cout <<" index j, j+1: " << j << "," << j+1 <<" swaping " << arr[j] << " and " << arr[j+1] << " || ";
        swap(arr[j], arr[j+1]);
        consoleArray(arr);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
}

int main()
{
  vector<int> array = {2, 4, 6, 5, 1, 3};
  cout << "array before sort: ";
  consoleArray(array);
  bubbleSort(array);
  cout << endl;

  return 0;
}
