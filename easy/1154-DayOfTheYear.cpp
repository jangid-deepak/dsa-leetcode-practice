#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
       int dayOfYear(string date) {
            vector<int> dateInt = split(date);
            bool isLeap = dateInt[0]%4 == 0;
            vector<int> months = {31, isLeap ? 29: 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            int ans = 0;
            for(int i=0; i<dateInt[1]-1; i++) {
                ans += months[i];
            } 
            return ans + dateInt[2];
       }
       vector<int> split(string date) {
            vector<int> ans;
            char delimiter = '-';
            size_t start = 0, end;
            while((end = date.find(delimiter, start)) != string::npos) {
                ans.push_back(stoi(date.substr(start, end-start)));
                start = end+1;
            }
            ans.push_back(stoi(date.substr(start)));
            return ans;
       }
};
int main() {
    Solution sol;
    
    int ans = sol.dayOfYear("2019-02-10");
    cout << "ans: " << ans << endl;
    return 0;
}