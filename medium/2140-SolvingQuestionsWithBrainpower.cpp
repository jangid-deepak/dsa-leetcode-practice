#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {

            int n = questions.size();
            vector<long long> dp(n+1, 0);
            for(int i=n-1; i>= 0; i--) {
                long long take = questions[i][0];
                int next = i+questions[i][1] + 1;
                if (next < n) take += dp[next];
                dp[i] = max(take, dp[i+1]);
            }
            return dp[0];
        }
    };
int main() {
    Solution sol;
    vector<vector<int>> questions = {{21,5},{92,3},{74,2},{39,4},{58,2},{5,5},{49,4},{65,3}};
    long long ans = sol.mostPoints(questions);
    cout << "ans: " << ans << endl;
    return 0;
}