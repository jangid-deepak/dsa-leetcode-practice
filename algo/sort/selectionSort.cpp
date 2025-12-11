#include <iostream>
#include <vector>

using namespace std;

void consoleArray(vector<int> &arr) {
  for (int num : arr) {
    cout << num << ' ';
  }
  cout << endl;
}

void selectionSort(vector<int> &arr) {
  int N = arr.size();
  for (int i = 0; i < N; i++) {
    int minIndex = i;
    for (int j = i + 1; j < N; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      swap(arr[i], arr[minIndex]);
    }
  }
}

int main() {
  vector<int> array = {2, 4, 6, 5, 1, 3};
  cout << "array before sort: ";
  consoleArray(array);
  selectionSort(array);
  consoleArray(array);
  return 0;
}
