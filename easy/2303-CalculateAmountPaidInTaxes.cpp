
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
    public:
        double calculateTax(vector<vector<int>>& brackets, int income) {
            double tax = 0;
            int prev = 0;
            for(int[] bracket : brackets) {
                int upper = bracket[0], percent = bracket[1];
                if (income >= upper) {
                    tax += (upper - prev) * percent / 100d;
                } else {
                    tax += (income - prev) * percent / 100d;
                    return tax;
                }
            }
            return tax;
        }
    };


int main() {
    Solution sol;
    vector<vector<int>> brackets = {{3,50},{7,10},{12,25}};
    double ans = sol.calculateTax(brackets ,10);
    cout << "ans: " << ans << endl;
    return 0;
}