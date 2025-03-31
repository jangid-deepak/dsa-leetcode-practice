#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Psuecode
 * START
 *  INPUT nums, k
 *  N = length of nums
 *  FOR i from 0 to N DO
 *      diff = 0;
 *      WHILE (diff < N) DO
 *          FOR j from i to N DO
 *          diff += 2;
 *  FOREND
 * END
 */

class Solution {
    public:
       int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
    
        // Generate all subarrays
        for (int start = 0; start < n; ++start) {
            int minElement = nums[start];
            for (int end = start; end < n; ++end) {
                minElement = min(minElement, nums[end]);
                if (minElement >= k) {
                    // Print valid subarray
                    cout << "[";
                    for (int i = start; i <= end; ++i) {
                        cout << nums[i] << (i < end ? ", " : "");
                    }
                    cout << "]\n";
                }
            }
        }
            return 0;
       }
};
int main() {
    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};
    int ans = sol.minCapability(nums, 2);
    cout << "ans: " << ans << endl;
    return 0;
}