#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int maxRepeating(string seq, string word) {
    int k = 0;
    string temp = word;

    while (seq.find(temp) != string::npos) {
      k++;
      temp += word;
    }
    return k;
  }
};

int main() {
  Solution sol;
  int ans = sol.maxRepeating("aaabaaaabaaabaaaabaaaabaaaabaaaaba", "aaaba");
  cout << "ans " << ans << endl;
}
