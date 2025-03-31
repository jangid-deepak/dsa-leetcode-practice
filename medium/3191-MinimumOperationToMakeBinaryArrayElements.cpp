#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int ans = 0;
            for(int i=0; i<=nums.size()-3; i++) {
                if (nums[i] == 0) {
                    ans++;
                    
                }
                cout << i<< ": ";
                display(nums);
            }

            for(int i=0; i<nums.size(); i++) {
                if (nums[i] == 0) return -1;
            }
            return ans;
        };

        void display(vector<int>& nums) {
            for(int num: nums) {
                cout << " " << num;
            }
            cout << endl;
        }
};
int main() {
    Solution sol;
    
    vector<int> nums = {1,0,1,0,0,0};
    int ans = sol.minOperations(nums);
    cout << "ans: " << ans << endl;
    return 0;
}