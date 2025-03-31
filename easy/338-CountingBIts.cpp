#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

class Solution {
    public:
        vector<int> countBits(int n) {
            vector<int> nums(n+1);
            for(int i=1; i<nums.size(); i++) {
                string binary = int2Binary(i);
                cout << " " << i <<" " << count1s(binary) << "\t" << binary << endl;
            }

            return nums;
        }

        string int2Binary(int n) {
            if (n == 0) {
                return "0";
            }
            string i;
            while(n > 0) {
                i += (n%2 == 0 ? '0' : '1');
                n /= 2;
            }
            reverse(i.begin(), i.end());
            return i;
        }

        int count1s(string s) {
            int c = 0;
            for(char ch: s) {
                if (ch == '1') c++;
            }

            return c;
        }
    };


int main() {
    Solution sol;
    
    vector<int> ans = sol.countBits(100);
    // for(int n: ans) {
    //     cout << " " << n;
    // }
    cout << endl;
    return 0;
}