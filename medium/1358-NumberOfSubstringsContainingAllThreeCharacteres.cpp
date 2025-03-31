#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Pseudocode
 * Sliding window
 * START
 *  INPUT s;
 *  n = length of s;
 *  DECLARE map as HASHMAP
 *  i=0;
 *  j=0;
 *  ans = 0;
 *  WHILE (j < n) DO
 *        map[s[j]]++;
 *        WHILE (map['a'] > 0 && map['b'] > 0 && map['c'] > 0) DO
 *              ans += (n -j);
 *              map[s[i]]--;
 *              i++;
 *         j++;
 * END
 * 
 * LAST KNOW POSITION
 * START
 *  INPUT s,
 *  n = length of s;
 *  lastPos = [-1, -1, -1];
 *  total = 0
 *  FOR pos 0 to n DO
 *      lastPos[s[pos] - 'a'] = pos;
 *      total += 1 + min(lastPos);
 *  FOREND
 *  return total
 * 
 * END
 */

class Solution {
    public:
       int numberOfSubstrings(string s) {
            int len = s.length();
            int left = 0, right = 0;

            vector<int> freq(3,0);
            int total = 0;
            while (right < len) {
                char ch = s[right];
                freq[ch - 'a']++;
                while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                    total += len - right;
                    char leftCh = s[left];
                    freq[leftCh - 'a']--;
                    left++;
                }
                right++;
            }
        return total;
       }
};
int main() {
    Solution sol;
    
    int ans = sol.numberOfSubstrings("abcabc");
    cout << "ans: " << ans << endl;
    return 0;
}