#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> getRow(int numIndex) {
    vector<int> row = {1};
    for (int i = 0; i < numIndex; i++) {
      vector<int> next;
      next.push_back(1);

      for (int j = 1; j < row.size(); j++) {
        next.push_back(row[j] + row[j - 1]);
      }
      next.push_back(1);
      row = next;
    }
    return row;
  }
};

int main() {
  cout << "progam is running";
  Solution sol;
  return 0;
}
