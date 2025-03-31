#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool rotateString(string s, string goal) {
            if (s.size() != goal.size()) return false;
            string ss= s+s;
            return ss.find(goal) < ss.length();
        }
    };
int main() {
    Solution sol;
    bool ans = sol.rotateString("abcde", "cdeab");
    cout << "ans: " << ans << endl;
    return 0;
}