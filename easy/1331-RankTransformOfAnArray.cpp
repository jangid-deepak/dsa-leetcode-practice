#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
    public:
        vector<int> arrayRankTransform(vector<int>& arr) {
            unordered_map<int, int> map;
            set<int> nums(arr.begin(), arr.end());
            int rank = 1;
            for(int num: nums) {
                map[num] = rank;
                rank++;
            }
            for(int i=0; i<arr.size(); i++) {
                arr[i] = map[arr[i]];
            }
            return arr;

        }
    };
int main() {
    Solution sol;
    vector<int> arr = {100,100,100};
    vector<int> ans = sol.arrayRankTransform(arr);
    for(int ele: ans) {
        cout << " " << ele;
    }
    cout << endl;
    return 0;
}