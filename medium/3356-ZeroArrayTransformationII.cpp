#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

/**
 * x x x
 * Pseudo Code
 * START
 *  INPUT nums, queries
 *  querySize = length of queries
 *  n = length of nums
 *  DECLARE set 0 to n-1
 *  FOR i from 0 to querySize -1 DO
 *     FOR Ith: set DO
 *          check if Ith is 0 do nothing
 *          check if Ith is not in range do nothing
 *              check if val >= Ith
 *                  Ith = 0;
 *                  set.erase()
 *                  else 
 *                  Ith -= val;
 *     if (set.empty()) return i+1;
 * 
 *        
 * END
 */

using namespace std;

class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n = nums.size(), left = 0, right = queries.size();

            if (!canFormZeroArray(nums, queries, right)) return -1;
            while (left <= right) {
                int mid = left + (right - left)/2;
                if (canFormZeroArray(nums, queries, mid)) {
                    right = mid -1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }


        bool canFormZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k) {
            int n= nums.size(), sum = 0;
            vector<int> diff(n+1);

            for(int qIndex=0; qIndex < k; qIndex++) {
                int start = queries[qIndex][0], end = queries[qIndex][1], val = queries[qIndex][2];
                diff[start] += val;
                diff[end+1] -= val;
            }

            for(int i=0; i<n; i++) {
                sum += diff[i];
                if (sum < nums[i]) return false;
            }
            return true;
        }
    };
int main() {
    Solution sol;
    vector<int> nums = {2,0,2};
    vector<vector<int>> queries = {{0,2,1}, {0,2,1}, {1,1,3}};
    int ans = sol.minZeroArray(nums, queries);
    cout << "ans: " << ans << endl;
    return 0;
}