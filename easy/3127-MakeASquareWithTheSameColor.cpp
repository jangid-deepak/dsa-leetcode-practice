#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        bool canMakeSquare(vector<vector<char>>& grid) {
            for(int i=0; i<=1; i++) {
                for(int j=0; j<=1; j++) {
                    int block = displayGrid(grid, i, j);
                    if (block >= 3) {
                        return true;
                    }
                }
            }
            return false;
        }
        int displayGrid(vector<vector<char>>& grid, int r, int c) {
            int maxW = 0;
            int maxB = 0;
            for(int i=r; i<r+2; i++) {
                for(int j=c; j<c+2; j++) {
                    if (grid [i][j] == 'W') {
                        maxW++;
                    } else {
                        maxB++;
                    }
                    
                }
            }
            return max(maxW++, maxB++);
        }
    };
int main() {
    Solution sol;
    vector<vector<char>> grid = {{'B','W','B'}, {'B','W','W'}, {'B','W','B'}};
    // sol.displayGrid(grid, 1, 0);
    bool ans = sol.canMakeSquare(grid);
    
    cout << "ans: " << ans << endl;
    return 0;
}