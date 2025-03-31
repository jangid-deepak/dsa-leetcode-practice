
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
    public:
        int minTimeToType(string word) {
            int ans = 0;
            int pos = 97;
            for(int i=0; i<word.size(); i++) {
                // direction true for cw false ccw
		int dis = abs(int(word[i] - pos));
                bool dir = dis < 13;
                if (dir) {
                    // cw
                    cout << "Move the pointer cw to: " << word[i] << " from: " << char(pos) << "seconds: " << dis <<endl;
                    ans += dis;
                } else {
                    // ccw
                    cout << "Move the pointer ccw to: " << word[i]  << " from: " << char(pos) << "seconds: " << dis <<endl;

                    ans += 26 - dis;               }
                cout << "Type the character: " << word[i] <<endl;
                ans++;

                pos = int(word[i]);
            }
            return ans;
        }
};


int main() {
    Solution sol;
    int ans = sol.minTimeToType("abc");
    cout << "answer: " << ans << endl;
    return 0;
}
