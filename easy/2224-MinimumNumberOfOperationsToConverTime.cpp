#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        int convertTime(string current, string correct) {
            int a = 0;
            vector<int> time = {60, 15, 5, 1};
            int i = 0;
    
    
            int minutes = diff(current, correct);
            cout << "minutes: " << minutes << endl;
            while (i < time.size()) {
                if (minutes%time[i] == 0) {
                    
                }
            }
            return a;
        }
    
        int diff(string current, string correct) {
            size_t pos = current.find(':');
            int curr_hour = stoi(current.substr(0, pos));
            int curr_min = stoi(current.substr(pos+1));


            pos = correct.find(':');
            int corr_hour = stoi(correct.substr(0, pos));
            int corr_min = stoi(correct.substr(pos+1));

            int min_diff = 0;
            if (corr_min >= curr_min) {
                min_diff = corr_min - curr_min;
            } else {
                min_diff = 60 + corr_min - curr_min;
                corr_hour--;
            }

            min_diff += (corr_hour - curr_hour) * 60;

            return min_diff;
        }
    };
int main() {
    Solution sol;
    int a = sol.convertTime("02:30", "04:35");
    cout << "ans: " << a << endl;
    return 0;
}