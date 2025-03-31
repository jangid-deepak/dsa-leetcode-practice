#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <limits.h>

using namespace std;

class Solution {
    public:
        int sum(vector<int>& nums) {
            int ans = 0;
            int maxN = INT_MIN;
            unordered_set<int> uniqeNums;

            for(int num: nums) {
                if (num > 0) {
                    uniqeNums.insert(num);
                } else {
                    maxN = max(num, maxN);
                }
            }
            for(int num: uniqeNums) {
                ans += num;
            }
            if (uniqeNums.size()) {
                return ans;
            } else {
                return maxN;
            }
        }
};
int main() {
    Solution sol;
    
    vector<int> nums = {2,-10,6};
    int ans = sol.sum(nums);
    cout << "ans: " << ans << endl;
    return 0;
}