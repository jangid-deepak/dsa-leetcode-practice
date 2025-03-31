#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
            int n = distance.size();


            // for(int i=start; ((i+1)%n) <= destination; i++) {
            //     cout << i << "->" << (i+1)%n << " " << distance[i] << endl;
            // }

            return 0;
        }
    };
int main() {
    Solution sol;
    vector<int> distance = {1,2,3,4};
    int start = 0;
    int destination = 2;

    int ans = sol.distanceBetweenBusStops(distance, start, destination);
    
    cout << "ans: " << ans << endl;
    return 0;
}