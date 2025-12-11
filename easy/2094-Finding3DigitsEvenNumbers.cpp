#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> findEvenNumbers(vector<int> &digits) {
  unordered_set<int> nums;
  int n = digits.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (i == j || j == k || i == k) {
          continue;
        }
        int num = digits[i] * 100 + digits[j] * 10 + digits[k];
        if (num >= 100 && num % 2 == 0) {
          nums.insert(num);
        }
      }
    }
  }
  vector<int> res;
  for (const int num : nums) {
    res.push_back(num);
  }
  sort(res.begin(), res.end());
  return res;
}

int main() {
  vector<int> input = {2, 1, 3, 0};
  vector<int> ans = findEvenNumbers(input);
  for (int num : ans) {
    cout << num << " ";
  }

  cout << endl;
  return 0;
}
