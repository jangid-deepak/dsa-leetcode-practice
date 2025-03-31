#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
        vector<vector<int>> ans;

        int i = 0, j = 1;
        while (j < s.size())
        {
            cout << i << " " << j << endl;
            if (s[i] == s[j])
            {
                j++;
            }
            else
            {

                if (j - i > 2)
                { 
                    cout << "pushing..." << endl;
                    ans.push_back({i, j-1});
                }
                i = j;
                j++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> ans = sol.largeGroupPositions("abcdddeeeeaabbbcd");
    for(vector<int> arr: ans) {
        cout << "["<<arr[0]<<", "<<arr[1]<<"]" << endl;
    }
    cout << endl;
    return 0;
}