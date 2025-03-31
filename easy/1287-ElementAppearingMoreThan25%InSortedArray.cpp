#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
       int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int percentage = (1/n)*100;
        int perInCrea = percentage; 

        for(int i=1; i<arr.size(); i++) {
            if (arr[i] == arr[i-1]) {
                percentage += perInCrea;
            } else {
                percentage = perInCrea;
            }

            if (percentage > 25) {
                return arr[i];
            }
        }

        return -1;
       }
};
int main() {
    Solution sol;
    vector<int> arr = {1,2,2,6,6,6,6,7,10};
    int ans = sol.findSpecialInteger(arr);
    cout << "ans: " << ans << endl;
    return 0;
}