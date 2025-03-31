#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
            vector<int> ans(10, 1);
            int test = 10;
            for(int i=0; i<nums.size(); i++) {
                cout << test + i << " " << i << endl;
            }

            return ans;
    }

};
int main() {
    Solution sol;
    int key = 9;
    int k = 1;
    vector<int> nums = {9, 1, 1, 1, 1};
    vector<int> ans = sol.findKDistantIndices(nums, key, k);
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    };
    cout << endl;
    return 0;
}