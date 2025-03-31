#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    public:
       int largestInteger(vector<int>& nums, int k) {
            int maxInt = -1;
            unordered_map<int, int> freq;
            for(int n: nums) freq[n]++;
            int ans = -1, maxM = -1, maxV = -1;
            for(int i=0; i<nums.size(); i++) {
                if (freq[nums[i]] == 1) maxM = max(maxM, nums[i]);
                maxV = max(maxV, nums[i]);
            }
            if (k == 1) return maxM;
            if (k == nums.size()) return maxV;
            if (freq[nums[0]] == 1) ans = max(ans, nums[0]);
            if (freq[nums.back()] == 1) ans = max(ans, nums.back());

            return ans;
       }
};
int main() {
    Solution sol;
    vector<int> nums = {3,9,7,2,1,7};
    int k = 4;
    int ans = sol.largestInteger(nums, k);
    cout << "ans: " << ans << endl;
    return 0;
}