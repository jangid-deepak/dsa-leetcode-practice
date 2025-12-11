#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
	public:
        string decodeMessage(string key, string message) {
            unordered_map<char, char> myMap;
            char currentChar = 'a';
            myMap[' '] = ' ';
            for(char ch: key) {
                if (ch != ' ' && !myMap[ch]) {
                myMap[ch] = currentChar;
                currentChar++;
            }   
            }
            //for(const auto& pair: myMap) {
            //cout << pair.first << " " << pair.second << endl;
        //      }
        //
            string ans;    
            for(char ch: message) {
            ans += myMap[ch];
        }
            return ans;
    }	
};

int main() {
    Solution sol;
    string ans = sol.decodeMessage("eljuxhpwnyrdgtqkviszcfmabo", "zwx hnfx lqantp mnoeius ycgk vcnjrdb");
    cout << "ans " << ans << endl;
	return 0;
}


