#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
    public:
       vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for(int i=0; i<nums.size(); i++) {
            unordered_set<int> prefix, suffix;
            for(int j = 0; j<nums.size(); j++) {
                if (j <= i) {
                    prefix.insert(nums[j]);
                } else {

                    suffix.insert(nums[j]);
                }
            }
            ans[i] = prefix.size() - suffix.size();
        }
        return ans;
       }
};
int main() {
    Solution sol;
    
    vector<int> nums = {1,2,3,4,5};
    vector<int> ans = sol.distinctDifferenceArray(nums);
    for(int a: ans) {
        cout << " " << a;
    }
    cout << endl;
    return 0;
}