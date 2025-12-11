#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int N = prices.size();
    int profit = 0;
    int index = 0;

    for (int i = 1; i < N; i++) {
      int ans = prices[i] - prices[index];
      cout << "ans " << ans << endl;
      if (ans > profit) {
        profit = ans;
      }
      // find the index which is minimum
      if (ans <= 0) {
        index = i;
      }
    }

    return profit;
  }
};

int main() {
  Solution sol;

  vector<int> prices = {7, 2, 4, 3, 1, 4};

  int ans = sol.maxProfit(prices);

  cout << ans << endl;
  return 0;
}
