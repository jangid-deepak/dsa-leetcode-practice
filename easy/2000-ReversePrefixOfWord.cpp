#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        string reversePrefix(string word, char ch) {
            int fr = -1;
            for(int i=0; i<word.size(); i++) {
                if (word[i] == ch) {
                    fr = i;
                    break;
                }
            }
            if (fr == -1) return word;
            cout << fr;
            string res  = "";
            for(int i=fr; i>=0; i--) {
                cout << i;
                res += word[i];
            };
    
            for(int i=fr+1; i<word.size(); i++) {
                res += word[i];
            };
    
            return res;
    
        }
    };

int main() {
    Solution sol;
    char ch = 'd';
    string ans = sol.reversePrefix("abcdefd", ch);
    cout << "ans: "  << ans << endl;
    return 0;
}