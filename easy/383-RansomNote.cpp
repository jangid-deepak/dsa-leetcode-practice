#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    public:
       bool canConstruct(string ransomNote, string magazine) {
            if (magazine.length() < ransomNote.length()) {
                return false;
            }

            unordered_map<char, int> freq;
            for(char ch: magazine) freq[ch]++;

            for(char ch: ransomNote) {
                if (freq[ch] == 0) return false;
                freq[ch]--; 
            }
            return true;

       }    
};
int main() {
    Solution sol;
    bool ans = sol.canConstruct("aa", "b");
    
    cout << "ans: " << ans << endl;
    return 0;
}