#include <iostream>
#include <vector>
#include <string>
using namespace std;

// class Solution {
//     public:
//        int longestNiceSubarray(vector<int>& arr) {
//             int ans = 0;
//             int n = arr.size();
//             for (int start = 0; start < n; ++start) {
//                 vector<int> subarray;
//                 for (int end = start; end < n; ++end) {
//                     subarray.push_back(arr[end]);
                    
//                     cout << "[";
//                     for (int num : subarray) {
//                         cout << num << " ";
//                     }
//                     cout << "]: ";
//                     if (isValidArray(subarray)) {
//                         if (ans < subarray.size()) {
//                             ans = subarray.size();
//                         }
//                     }
//                     cout << isValidArray(subarray) << endl;
//                 }
//             }
//             return ans;
//        }

//        bool isValidArray(vector<int> arr) {
//             if (arr.size() == 1) return true;
//             for(int i = 0; i<arr.size()-1; i++) {
//                 for(int j=i+1; j < arr.size(); j++) {
//                     if (isValidPair(arr[i], arr[j])) return false;
//                 }
//             }
//             return true;
//        }

//        bool isValidPair(int num1, int num2) {
//         return num1 & num2;
//        }
// };

class Solution {
    public:
        int longestNiceSubarray(vector<int>& arr) {
            int ans = 1;
            int i=0, j=1;
            int n = arr.size();
            while (i<n && j<n) {
                if (!(arr[i] & arr[j])) {
                    j++;
                } else {
                    i=j;
                    j++;
                }
                if (ans < j-i) {
                    ans = j-i;
                } 
                cout << "i: " << i << " j: " << j << endl;
            }
            return ans;
        }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 3, 3, 3, 3, 3, 3, 3};
    int ans = sol.longestNiceSubarray(nums);
    cout << "ans: " << ans << endl;
    return 0;
}