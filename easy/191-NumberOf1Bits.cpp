#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
       int hammingWeight(int n) {
            int ans = 0;
            while (n != 0) {
                if (n%2 == 1) ans++;
                n = n/2;
            }
            return ans;
       }
};
int main() {
    Solution sol;
    
    int ans = sol.hammingWeight(2147483645);
    cout << "ans: " << ans << endl;
    return 0;
}