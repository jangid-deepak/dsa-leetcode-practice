#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int countAsterisks(string s) {
            int ans = 0;
            bool start = false;
            for(int i=0; i<s.size(); i++) {
                if (s[i] == '|') {
                    start = !start;
                }

                if (s[i] == '*' && !start) {
                    ans++;
                }
            }
            return ans;
        }
};

int main() {
    Solution sol;
    cout << "counts: " << sol.countAsterisks("yo|uar|e**|b|e***au|tifu|l") << endl;
    return 0;
}