#include <iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
    public:
        bool checkPowersOfThree(int n) {
            // do
            do {
                int rem = n%3;
                cout << "n: " << n << endl;
                cout << "rem: " << rem << endl;
                if (rem == 2) {
                    return false;
                }
                n = n/3;
            } while (n > 0);
            return true;
        }
        
};


int main() {
    Solution sol;
    bool ans = sol.checkPowersOfThree(12);
    cout << "ans: " << ans << endl;
    
    return 0;
}