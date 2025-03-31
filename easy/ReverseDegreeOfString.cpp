#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        int reverseDegree(string s) {
            int ans = 0;
            for(int i=0; i<s.size(); i++) {
                int vl = (97 + 26 - int(s[i])) * (i+1);
                ans += vl;
            }
            return ans;
        }
    };
int main() {
    Solution sol;
    int a = sol.reverseDegree("zaza");
    
    cout << "ans: " << a << endl;
    return 0;
}