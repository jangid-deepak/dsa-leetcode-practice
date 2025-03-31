#include <iostream>
#include <vector>
#include <string>
#include <algorith>

using namespace std;


/**
 * START
 *  INPUT days, meetings
 *  sort the meetings by start day
 * 
 *  DECLARE currentDay, availableDays
 * 
 *  FOR each meeting in meetings DO
 *      start, end = meeting;
 *      if currentDay < start 
 *          availableDays += (start- currentDay)
 *      currentDay = max(currentDay, end+1)
 * 
 *   if currentDay <= days
 *         availableDayas += (days- currentDay + 1) 
 * END
 */

class Solution {
    public:
       int countDays(int days, vector<vector<int>>& meetings) {
            int ans = 0;
            

            return ans;
       }
};
int main() {
    Solution sol;
    
    vector<vector<int>> meetings = {{5, 7}, {1, 3}, {9, 10}};
    int ans = sol.countDays(10, meetings);
    cout << "ans: " << ans << endl;
    return 0;
}