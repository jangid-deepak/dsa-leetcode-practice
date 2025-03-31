#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>


using namespace std;

class Solution {
    public:
       long long pickGifts(vector<int>& gifts, int k) 
       {
        long long ans = 0;
        priority_queue<int> giftHeaps(gifts.begin(), gifts.end());
        for(int i=0; i < k; i++) 
        {
            int maxEle = giftHeaps.top();
            giftHeaps.pop();
            giftHeaps.push(sqrt(maxEle));
        }

        while (!giftHeaps.empty())
        {
            ans+= giftHeaps.top();
            giftHeaps.pop();
        }
        return ans;
        
       }
};
int main() {
    Solution sol;
    vector<int> gifts = {25, 64, 9, 4, 100};
    int k = 4;
    long long ans = sol.pickGifts(gifts, k);
    cout << "ans: " << ans << endl;
    return 0;
}