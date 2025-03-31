#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isCircularSentence(string s) {
        int n = s.size();
        if (s[0] != s[n-1]) return false;
        for(int i=0; i<n; i++) {
            if (s[i] == ' ' && s[i-1] != s[i+1]) return false;
        }
        return true;
    }

};
int main() {
    Solution sol;
    
    bool ans = sol.isCircularSentence("Leetcode is cool");
    cout << "ans: " << ans << endl;
    return 0;
}