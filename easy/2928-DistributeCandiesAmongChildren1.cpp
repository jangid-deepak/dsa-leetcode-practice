#include <iostream>

using namespace std;

class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans = 0;
        int maxFirst = max(0, n - 2*limit);
        int minFirst = min(n, limit);

        for(int i=minFirst; i <= maxFirst; i++) {
            int N = n - i;
            int minCh2 = max(0, N - limit);
            int maxCh2 = min(N, limit);

            ans += maxCh2 - minCh2 + 1;
        }
        return ans;
    }
};


int main() {
    Solution sol;

    int ans = sol.distributeCandies(5, 2);

    cout << "ans :" << ans << endl;
    return 0;
}
