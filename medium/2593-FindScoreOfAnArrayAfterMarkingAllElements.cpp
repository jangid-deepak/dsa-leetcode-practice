#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
    public:
        long long findScore(vector<int>& nums) {
            int n = nums.size();
            long long score = 0;
            unordered_set<int> unmarkedIndices;
            for(int i=n-1; i >= 0; i--) {
                unmarkedIndices.insert(i);
            }
            while (!unmarkedIndices.empty()) {
                int minIndex = -1;
                int min = INT_MAX;
                for(int i: unmarkedIndices) {
                    cout <<" i: " << i << endl; 
                    if (min > nums[i]) {
                            min = nums[i];
                            minIndex = i;
                        }
                    }
                if (minIndex == -1) {
                    break;
                }
                cout << min << " index: "  << minIndex << endl;
                score += min;

                // marking
                unmarkedIndices.erase(minIndex);
                if (minIndex >= 1) unmarkedIndices.erase(minIndex - 1);
                if (minIndex <= n-2) unmarkedIndices.erase(minIndex + 1);
            }
            return score;
        }
    };

int main() {
    Solution sol;
    
    vector<int> nums = {5,1,1,7,2,4};
    long long ans = sol.findScore(nums);
    cout << "ans: " << ans << endl;
    return 0;
}