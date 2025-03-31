#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
       int singleNumber(vector<int>& nums) {
            int ans = 0;
            for (int num: nums) {
                ans = ans^num;
            } 
            return ans;
       }
};
int main() {
    Solution sol;
    vector<int> nums = {2,1,2};
    int ans = sol.singleNumber(nums);
    cout << "ans: " << ans << endl;
    return 0;
}