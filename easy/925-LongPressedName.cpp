#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        bool isLongPressedName(string name, string typed) {
            int i = 0;
            int j = 0;
            while(i < name.length() && j < typed.length()) {
                if (name[i] == typed[j]) {
                    i++;
                    j++;
                } else if (j >= 1 && (typed[j] == typed[j-1])) {
                    j++;
                } else {
                    return false;
                }
            }
            if (i != name.length()) {
                return false;
            } else {
                while(j < typed.length()) {
                    if (typed[j] != typed[j -1]) {
                        return false;
                    }
                    j++;
                }
            }
            return true;
        }
    };
int main() {
    Solution sol;
    bool ans = sol.isLongPressedName("alex", "aaleex");
    
    cout << "ans: " << ans << endl;
    return 0;
}