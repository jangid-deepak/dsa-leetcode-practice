#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
    public:
        long long makeIntegerBeautiful(long long n, int target) {
            long long n0 = n, base = 1;
            while (sum(n) > target) {
                n = n/10 + 1;
                cout << "n: " << n << endl;
                base *=10;
            }
            return n*base - n0;
        }
        int sum(long long n) {
            int res = 0;
            while(n) {
                res += n%10;
                n /= 10;
            }
            return res;
        }
    };
int main() {
    Solution sol;
    long long ans = sol.makeIntegerBeautiful(467, 6);
    
    // for (int i=456; i<1000; i++) {
    //     sol.makeIntegerBeautiful(i, 6);
    // }

    cout << "ans: " << ans << endl;
    return 0;
}