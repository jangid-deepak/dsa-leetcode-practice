
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<int> circularGameLosers(int n, int k)
    {
        vector<int> arr(n);
        int flag = true;
        int i = 0;
        int step = 0;
        while (flag) {
            i++;
            if (arr[step % n] == 1) {
                break;
            } else {
                arr[step % n] = 1;
            }
            step += i * k;
        }

        vector<int> ans;
        for(int i=0; i<arr.size(); i++) {
            if (arr[i] == 0) {
                ans.push_back(i+1);
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            cout << "at: " << i + 1 << " " << ans[i] << endl;
        }


        return ans;
    }
};
int main()
{
    Solution sol;
    sol.circularGameLosers(5, 2);
    return 0;
}