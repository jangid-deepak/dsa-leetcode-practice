#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int countValidWords(string sentence)
    {
        vector<string> tokens;
        size_t start = 0, end;

        while ((end = sentence.find(' ', start)) != string::npos)
        {
            tokens.push_back(sentence.substr(start, end - start));
            start = end + 1;
        }
        tokens.push_back(sentence.substr(start));
        for (string s : tokens)
        {
            cout << "s: " << s << " isValid: " << isValid(s) << endl;
        }
        return 0;
    }

    bool isValid(string s)
    {
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ') return false;
            if ((s[i] == '-') && (i == 0 || i == n - 1))
            {
                return false;
            }
            else if (isdigit(s[i]))
            {

                .
                return false;
            }
            else if ((s[i] == '.' || s[i]== '!' || s[i] == ',') && (i != n -1)) {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution sol;
    int ans = sol.countValidWords("cat and     dog");
    cout << "ans: " << ans << endl;
    return 0;
}