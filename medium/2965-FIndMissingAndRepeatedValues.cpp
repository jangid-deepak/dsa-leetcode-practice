#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int size = grid.size();
            int sumAc = 0;
            int sumSqureAc = 0;
            for(int i=0; i<size; i++) {
                for(int j=0; j<size; j++) {
                    sumAc += grid[i][j];
                    sumSqureAc += (grid[i][j])*(grid[i][j]);
                }
            }
            int n = size*size;
            int sumExp = n*(n + 1)/2;
            int sumSqureExp = (n*(n + 1)*(2*n + 1))/6;
            int a = sumExp - sumAc;
            int b = sumSqureExp - sumSqureAc;

            int d = (b - a*a)/(2*a);
            int r = d + a;

            return {r, d};
        }
};
int main() {
    Solution sol;
    vector<vector<int>> input = {{1, 3}, {2, 2}};
    // vector<vector<int>> input = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    vector<int> ans = sol.findMissingAndRepeatedValues(input);
    cout << "Hello, World! " << ans[0] << " " << ans[1] << endl;
    return 0;
}