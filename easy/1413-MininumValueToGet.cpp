#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
       int minStartValue(vector<int>& nums) {
            int minSum = 10000;
            int sum = 0;
            for(int i=0; i<nums.size(); i++) {
                sum += nums[i];
                if (minSum > sum) {
                    minSum = sum;
                }
            }
            cout << minSum;
            if (minSum >=0) {
                return 1;
            }
            return abs(minSum) + 1;
       }
};
int main() {
    Solution sol;
    
    vector<int> nums = {-3,2,-3,4,2};
    int ans = sol.minStartValue(nums);
    cout << "ans: " << ans << endl;
    return 0;
}