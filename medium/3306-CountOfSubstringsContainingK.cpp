#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * X X X:
 * Pesudo code
 * START
 *  INPUT string s, int k
 *  DECLARE map as HASHMAP
 *  FOR char: s
 *      map[s]++;
 *  ENDFOR
 *  DECLARE min
 *  FOR char: 'aeiou'
 *      min = min(min, map[s])
 *      IF map[s] == 0
 *          return 0
 *  
 *  IF map["con"] > k
 *      return min;
 * END
 */

 /**
  * Pseudocode
  * START
  *     INPUT string s, int k
  *     n = length of s
  *     count = 0
  *     DECLARE vowels AS SET = {a, e, i, o, u}
  *     DECLARE foundVowels AS EMPTY SET
  *     FOR i FROM 0 to n - k - 5 DO
  *         substring = s[i, i+k+5];
  *         conk = 0;
  *         FOR EACH char IN substring DO
  *             IF char IS IN vowels THEN
  *                 ADD char TO foundVowels
  *             ELSE
  *                 conk++;
  *             ENDIF
  *         ENDFOR
  *         if (foundVowels CONTAINS ALL vowerls AND conk > k)
  *             count++
  * 
  *             
  * 
  *     return count;
  * 
  *     FUNCTION checkV
  * END
  */

class Solution {
    public:
        long long countOfSubstrings(string word, int k) {
            
        }
};
int main() {
    Solution sol;
    
    
    cout << "ans: " <<  << endl;
    return 0;
}