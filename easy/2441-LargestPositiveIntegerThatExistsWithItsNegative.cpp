#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;
class Solution {
    public:
        int findMaxK(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            int i=0, j=n-1;
            while (i < j) {
                if( -nums[i] == nums[j]) {
                    return nums[j];
                } else if (-nums[i] > nums[j]) {
                    i++;
                } else {
                    j--;
                }
            }
            return -1;
        }
    };
int main() {
    Solution sol;
    vector<int> nums = {-1,10,6,7,-7,1};
    int ans = sol.findMaxK(nums);
    
    cout << "ans: " << ans << endl;
    return 0;
}