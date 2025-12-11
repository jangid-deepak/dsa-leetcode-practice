#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {

    vector<vector<int>> ans;
    ans.push_back({1});
    int n = 1;
    while (n < numRows) {
      vector<int> currentRow = ans.back();
      int crSize = currentRow.size();
      vector<int> nextRow(crSize + 1);
      nextRow[0] = 1;
      nextRow[crSize] = 1;
      int index = 1;

      for (int i = 0; i < crSize - 1; i++) {
        nextRow[index++] = currentRow[i] + currentRow[i + 1];
      }

      ans.push_back(nextRow);
      n++;
    }

    return ans;
  }
};

int main() {
  cout << "progam is running";
  Solution sol;
  vector<vector<int>> ans = sol.generate(6);

  cout << "[ ";
  for (vector<int> nums : ans) {
    cout << "[ ";
    for (int num : nums) {
      cout << num << ", ";
    }
    cout << "]";
  }

  cout << "]" << endl;
  return 0;
}
