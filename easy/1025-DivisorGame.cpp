#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  bool divisorGame(int n) {

    bool isAliceTurn = true;
    while (n > 1) {
      cout << "n " << n << endl;
      if (isAliceTurn) {
        cout << "alice choosing... ";
        isAliceTurn = !isAliceTurn;
      } else {
        cout << "bob choosing... ";
      }

      cout << "choice : ";
      int maxV = 0;
      for (int i = 1; i < n; i++) {

        if (n % i == 0) {
          maxV = maxV < i ? i : maxV;
          cout << " " << i;
        }
      }
      cout << " selected: " << maxV;
      cout << endl;
      n = n - maxV;
    }
    return 0;
  }
};

int main() {
  Solution sol;
  int ans = sol.divisorGame(100);
  cout << "ans " << ans << endl;
  return 0;
}
