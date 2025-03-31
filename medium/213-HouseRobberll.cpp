#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
       int rob(vector<int>& nums) {
            int evenSum = 0;
            int oldSum = 0;
            for (int i=0; i <= nums.size()-2; i++) {
                if (i%2 == 0) {
                    evenSum += nums[i];
                } else {
                    oldSum += nums[i];
                }
            }
            int maxS = max(evenSum, oldSum);
            evenSum = 0;
            oldSum = 0;
            for(int i=1; i <= nums.size() -1; i++) {
                if (i%2 == 0) {
                    evenSum += nums[i];
                } else {
                    oldSum += nums[i];
                }
            }
            int maxS1 = max(evenSum, oldSum);
            return max(maxS, maxS1);
       }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int ans = sol.rob(nums);
    cout << "ans: " << ans << endl;
    return 0;
}