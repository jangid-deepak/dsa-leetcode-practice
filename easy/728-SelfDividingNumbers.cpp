#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left; i<=right; i++) {
            if (isSelfDividing(i)) 
                ans.push_back(i);
        }

        return ans;
    }

    bool isSelfDividing(int num) {
        // get the digits
        int n = num;
        while (n > 0) {
            int digit = n%10;
            if (digit == 0 || num%digit != 0) return false;
            n /= 10;
        }
        return true;
    }

};

int main() {
    Solution sol;

    vector<int> ans = sol.selfDividingNumbers(1, 32);
    for(int num: ans) {
        cout << " " << num;
    }
    cout << endl;

    return 0;
}
