#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    public:
       int minmumIndex(vector<int>& nums) {
            unordered_map<int, int> firstMap, secondMap;
            int n = nums.size();
            for(int num: nums) {
                secondMap[num]++;
            }

            for(int index=0; index<n; index++) {
                int num = nums[index];
                secondMap[num]--;
                firstMap[num]++;

                if (firstMap[num]*2 > index + 1 && secondMap[num] * 2 > n - index - 1) return index;
            }
            return -1;
       }
};
int main() {
    Solution sol;
    vector<int> nums = {2,1,3,1,1,1,7,1,2,1};
    int ans = sol.minmumIndex(nums);
    cout << "ans: " << ans << endl;
    return 0;
}