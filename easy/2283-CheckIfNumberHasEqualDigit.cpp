#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        bool digitCount(string num) {
            unordered_map<char, int> map;
            for(int i=0; i<num.size(); i++) {
                if (map[num[i]] != 0) {
                    map[num[i]] += 1;
                } else {
                    map[num[i]] = 1;
                }
            }

            for(int i=0; i<num.size(); i++) {
                // cout << "The digit " <<  i << " occurs " << num[i] << " in num." << endl;
                // if (map[num[i]] != i) {
                //     return false;
                // }
                cout << map[i + '0'] << num[i] << ((map[i+'0'] + '0') == num[i]);

                if (map[i+'0'] == num[i]) {
                    return false;
                }
            }
            return true;
        }
};
int main() {
    Solution sol;
    bool ans = sol.digitCount("1210");
    cout << "ans: " << ans << endl;
    return 0;
}