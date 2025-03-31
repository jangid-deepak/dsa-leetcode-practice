#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {

            for(int i=0; i<(nums.size() - 1); i++) {
                // check condition
                if (nums[i] == nums[i+1]) {
                    nums[i] *=2;
                    nums[i+1] = 0;
                }
            }
            // swap the position with zeros
            shiftAllZeros(nums);
            return nums;
        }

        void swap(vector<int>& nums, int i, int j) {
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
        }


        void shiftAllZeros(vector<int>& nums) {
            int lkp = nums.size();
            bool flag = false;
            for(int i=0; i<nums.size(); i++) {
                if (nums[i] == 0) {
                    if (!flag) {
                        // zero trailing flag true
                        flag = true;

                        // updating last known location
                        lkp = i;
                    }
                } else if ((nums[i] != 0) && flag) {
                    swap(nums, i, lkp);
                    lkp++;
                }
            }
            
        }

        void displayArray(vector<int>& nums) {
            for(int i=0; i<nums.size();  i++) {
                cout << i << " " << nums[i] << endl;
            }
        }
};

int main() {

    Solution sol;

    vector<int> nums = {1, 0};
    vector<int> ans = sol.applyOperations(nums);
    sol.displayArray(ans);

    return 0;
}