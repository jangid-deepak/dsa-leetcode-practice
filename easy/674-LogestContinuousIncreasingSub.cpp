#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int findLengthOfLCIS(vector<int>& nums) {
            int count = 1;
            int maxCount = 1;
            for(int i=1; i<nums.size(); i++) {
                if (nums[i-1] < nums[i] ) {
                    count ++;
                } else {
                    
                    if (count >= maxCount) {
                        maxCount = count;
                    }
                    count = 1;
                }
                cout << "at " << nums[i] <<  " count: " << count << " maxCount " << maxCount << endl;
            }
            return count >= maxCount ? count : maxCount;
        }
        
};
int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 4, 2, 3, 4, 5, 6, 7, 8};
    Solution sol;
    cout << sol.findLengthOfLCIS(nums) << endl;
    return 0;
}