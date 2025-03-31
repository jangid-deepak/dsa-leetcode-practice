#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        string reformat(string s) {
           string digits;
           string nums;
            for(char ch: s) {
                if (isdigit(ch)) digits.push_back(ch);
                if (isalpha(ch)) nums.push_back(ch);
            }
            int m = digits.size();
            int n = nums.size();
            if (m == 0) return "";
            if (n == 0) return "";
            if (abs(m - n) > 1) return "";
            string ans;
            int i=0, j = 0;
            while (((i < m) && (j < n))) {
                if (m > n) {
                    ans.push_back(digits[i]);
                    ans.push_back(nums[j]);

                } else {
                    ans.push_back(nums[j]);
                    ans.push_back(digits[i]);
                }
                i++;
                j++;
            }
            if (i == m-1) ans.push_back(digits[i]);
            if (j == n-1) ans.push_back(nums[j]);
            return ans;
        }
    };
int main() {
    Solution sol;
    
    string ans = sol.reformat("a0b1c2tg2");
    // for (char ch: ans) 
    //     cout << ch << " " << endl;
    cout << "ans: " << ans << endl;
    return 0;
}