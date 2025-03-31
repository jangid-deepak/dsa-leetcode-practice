#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        string thousandSeparator(int n) {
            string ans = to_string(n);
            int N = ans.size();
            cout << N << endl;
            if (N <= 3) return ans;
            for(int i = N-3; i>=0; i -= 3) {
                cout << i << endl;
                ans = ans.substr(0, i) + "." + ans.substr(i, ans.size());
            }

            return ans;
            // string ans = "";
            // while(true) {
            //     ans = to_string(n%1000) + "." + ans;
            //     n = n/1000;
            //     if(n == 0) break;
            // }
            // return ans.substr(0, ans.length() -1);
        }
    };
int main() {
    Solution sol;
    
    string ans = sol.thousandSeparator(978);
    cout << "ans: " << ans << endl;
    return 0;
}