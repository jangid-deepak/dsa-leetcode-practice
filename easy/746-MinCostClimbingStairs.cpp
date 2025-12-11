#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int min(int x, int y) { return x < y ? x : y; }

int helper(vector<int> &cost, int i) {
  if (i == 0 || i == 1)
    return cost[i];
  return min(helper(cost, i - 1), helper(cost, i - 2)) + cost[i];
}

int minCostClimbingStairs(vector<int> &cost) {
  int n = cost.size();
  // return min(helper(cost, n - 1), helper(cost, n - 2));
  vector<int> dp(n);
  dp[0] = cost[0];
  dp[1] = cost[1];

  for (int i = 2; i <= n; i++) {
    dp[i] = cost[i] + min(dp[i - 2], dp[i - 1]);
  }
  return min(dp[n - 1], dp[n - 2]);
}
int main() {
  vector<int> nums = {10, 15, 20};
  int ans = minCostClimbingStairs(nums);
  cout << ans << endl;
  return 0;
}
