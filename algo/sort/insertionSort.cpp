#include <iostream>
#include <vector>

using namespace std;

void consoleArray(vector<int> &arr) {
  for (int num : arr) {
    cout << num << ' ';
  }
  cout << endl;
}

void insertionSortWhileLoop(vector<int> &arr) {
  int i = 1;
  int N = arr.size();
  while (i < N) {
    int j = i;
    while (j > 0 && (arr[j - 1] > arr[j])) {
      swap(arr[j - 1], arr[j]);
      cout << "Swaping " << arr[j - 1] << " and " << arr[j] << " || ";
      consoleArray(arr);
      j--;
    }
    i++;
  }
}

void insertionSortWithForLoop(vector<int> &arr) {

  for (int i = 1; i < arr.size(); i++) {
    for (int j = i; j > 0 && (arr[j - 1] > arr[j]); j--) {
      swap(arr[j - 1], arr[j]);
      cout << "Swaping " << arr[j - 1] << " and " << arr[j] << " || ";
      consoleArray(arr);
    }
  }
}

void insertionSortWithShift(vector<int> &arr) {

  for (int i = 1; i < arr.size(); i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && (arr[j] > key)) {
      arr[j + 1] = arr[j];
      cout << "placing " << j << " with " << j + 1 << " key " << key << " || ";
      j--;
      consoleArray(arr);
    }
    cout << i << " placing key value || ";
    arr[j + 1] = key;
    consoleArray(arr);
  }
}

int main() {
  vector<int> arr = {2, 4, 6, 5, 1, 3};
  cout << "Array before sort: ";
  consoleArray(arr);
  insertionSortWithShift(arr);
  consoleArray(arr);
  return 0;
}
