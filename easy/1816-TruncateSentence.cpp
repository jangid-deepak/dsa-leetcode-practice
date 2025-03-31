#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        string truncateSentence(string s, int k) {
            vector<string> tokens;
            size_t start = 0;
            size_t end = s.find(" ");
            while (end != string::npos) {
                tokens.push_back(s.substr(start, end - start));
                start = end + 1;
                end = s.find(" ", start);
            }
            tokens.push_back(s.substr(start));

            string ans;

            for(int i=0; i<k; i++) {
                if (i == 0) {
                    ans += tokens[i];
                } else {
                    ans += " " + tokens[i];
                }
            }

            return ans;
        }
};
int main() {
    Solution sol;
    cout << sol.truncateSentence("Hello how are you Contestant", 4) << endl;
    return 0;
}