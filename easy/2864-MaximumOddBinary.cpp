#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        string maximumOddBinaryNumber(string s) {
            int ones = 0;
            for(char ch: s) {
                if (ch == '1') ones++;
            }
            string ans((ones-1), '1');
            ans.append(s.size() - ones, '0');
            ans += '1';
            return ans;
        }
    };
int main() {
    Solution sol;
    
    string ans = sol.maximumOddBinaryNumber("0111");

    cout << "ans: " << ans << endl;
    return 0;
}