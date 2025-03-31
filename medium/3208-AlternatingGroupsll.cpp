#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            // two pass
            int count = 0;
            int isAlternative = 1;
            int last = colors[0];
            int N = colors.size();
            for(int i=1; i<N+k-1; i++) {
                int index = i%N;
                
                if (colors[index] == last) {
                    isAlternative = 1;
                    last = colors[index];
                    continue;
                }

                isAlternative += 1;
                if (isAlternative >= k) count++;
                last = colors[index];
            }
            return count;
            // sliding window
            // for(int i=0; i<k-1; i++) {
            //     colors.push_back(colors[i]);
            // }

            // int count = 0; 
            // int N = colors.size();
            // int left = 0;
            // int right = 1;
            // while(right < N) {
            //     if (colors[right] == colors[right-1]) {
            //         left = right;
            //         right++;
            //         continue;
            //     }
            //     right++;
            //     if (right-left < k) continue;
            //     count++;
            //     left++;
            // }
            // return count;

            // brute force
            // for(int i=0; i<N; i++) {
            //     bool inAlternative = true;
            //     for(int j=i+1; j<i+k; j++) {
            //         int index = j%N;
            //         int index1 = (j-1)%N;
            //         cout << "Index J: " << j <<" index: " << index << " index-1: " << index1 << endl;
            //         if (colors[index] == colors[index1]) {
            //             cout << "mismatched...!" << endl;
            //             inAlternative = false;
            //             continue;
            //         }
            //     }
            //     if (inAlternative) count++;
            //     cout << "current count: " << count << endl;
            // }
            // return count;



        };
    };
int main() {
    Solution sol;
    vector<int> colors = {0,1,0,0,1,0,1};
    int k = 6;
    int ans = sol.numberOfAlternatingGroups(colors, k);
    cout << "ans: " << ans << endl;
    return 0;
}