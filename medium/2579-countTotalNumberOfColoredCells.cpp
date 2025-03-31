#include <iostream>

using namespace std;

class Solution {
    public:
        long long coloredCells (int n) {
            long long ans = 2*n*(n-1) + 1;
            return ans;
        }
};

int main() {
    Solution sol;
    cout << sol.coloredCells(4) << endl;
    return 0;
}