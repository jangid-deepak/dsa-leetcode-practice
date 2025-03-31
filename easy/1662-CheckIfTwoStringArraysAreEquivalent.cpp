#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
            unordered_map<char, int> myMap;
            for(string word: word1) {
                for(char ch: word) {
                    myMap[ch]++;
                }
            }
    
            for(string word: word2) {
                for(char ch: word) {
                    if (myMap[ch] == 0) return false;
                    myMap[ch]--;
                }
            }
            return true;
        }
    };
int main() {
    Solution sol;
    vector<string> word1 = {"ab", "c"};
    vector<string> word2 = {"a", "cb"};

    bool ans = sol.arrayStringsAreEqual(word1, word2);

    cout << "ans: " << ans << endl;
    return 0;
}