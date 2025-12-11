#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * DP: is powerful algorithmic technique used to solve optimization and combinatorial problems by breaking them down into smaller overlapping subproblem
 */

int fibMemoization(int, vector<int>& dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int fibTabulation(int n) {
    vector<int> dp(n+1);
    dp[0] = 0, dp[1] = 1;
    for(int i=2; i<= n; i++) {
        dp[i] = dp[i-1] + dp[i - 2];
    }
    return dp[n];
}

int fibOptimizedSpace(int n) {
    if (n <= 1) return n;
    int prev2 = 0, prev1 = 1;
    for(int i=2; i<= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {


    return 0;
}