#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
       int getMax(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        if (n%2 == 0) {
            return getMax(n/2);
        } else {
            return (getMax(((n-1)/2)) + getMax(((n-1)/2) + 1));
        }
       }
    int getMaximumGenerated(int n) {
        vector<int> nums(n+1);
        if (n <= 1) return n;
        nums[1] = 1;
        int maxi = 0;
        for(int i=2; i<=n; i++) {
            if (i%2 == 0) {
                nums[i] = nums[i/2];
            } else if (nums[i%2 != 0]) {
                nums[i] = nums[i/2] + nums[i/2 + 1];
            }
            maxi = max(maxi, nums[i]);
        }

        return maxi;
    }
};
int main() {
    Solution sol;
    
    int ans = sol.getMax(1000000000);
    int ans1 = sol.getMaximumGenerated(1000000000);
    cout << "ans: " << ans << endl;
    cout << "ans1: " << ans1 << endl;

    return 0;
}