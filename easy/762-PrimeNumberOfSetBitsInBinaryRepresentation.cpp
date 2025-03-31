#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
       int displayBinary(int left, int right) {
        int ans = 0;
        for(int i=left; i <= right; i++) {
            cout << i << endl;
            int ones = decToBinary(i);
            if (isPrime(ones)) {
                ans++;
            }
        }
        return ans;
       }
       bool isPrime(int n) {
            vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
            for(int p: primes) {
                if (p == n) {
                    return true;
                }
            }
            return false;
       }
       int decToBinary(int n) {
        int count = 0;
        while (n > 0) {
            int bit = n%2;
            if (bit == 1) count++;
            n /= 2;
        }
        return count;
       }
};
int main() {
    Solution sol;
    
    int ans = sol.displayBinary(6, 10);
    cout << "ans: " << ans << endl;
    return 0;
}