#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
       int smallestEvenMultiple(int n) {
        return n%2 == 0 ? n: n*2;
       }

};
int main() {
    Solution sol;
    
    int ans = sol.smallestEvenMultiple(5);
    cout << "ans: " << ans << endl;

    // cout << sol.gcd(12, 18) << endl;
    return 0;
}