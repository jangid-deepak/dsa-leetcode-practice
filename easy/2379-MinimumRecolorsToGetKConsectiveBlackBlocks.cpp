#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
       int minimumRecolors(string blocks, int k) {
            int minS = 1000;
            cout << "block size: " << blocks.size()<< endl;
            for(int i=0; i<blocks.size() - k + 1; i++) {
                int min = 0;
                string s = "";
                for(int j=i; j<i+k; j++) {
                    s += blocks[j];
                    if (blocks[j] == 'W') {
                        min++;
                    }
                }
                cout << "i: " << i << " s: " << s  << "size:" << s.size() << endl;
                if (minS > min) {
                    minS = min;
                }
            }
            return minS;
       }
};
int main() {
    Solution sol;
    
    int ans = sol.minimumRecolors("BWBBWWBBBWBWWWBWWBBWBWBBWBB", 11);
    cout << "ans: " << ans << endl;
    return 0;
}