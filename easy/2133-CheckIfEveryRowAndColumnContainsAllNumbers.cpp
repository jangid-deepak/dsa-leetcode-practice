#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        bool checkValid(vector<vector<int>>& matrix) {
            int n = matrix.size();
            for(int i = 0; i < n; i++) {
                unordered_set<int>oneset,secondset;
    
                for(int j = 0; j < n; j++) {
                    oneset.insert(matrix[i][j]);
                    secondset.insert(matrix[j][i]);
                }
                cout << "column.size(): " << oneset.size() << endl;
                cout << "rows.size(): " << secondset.size() << endl;
                if ((oneset.size() != n) || (secondset.size() != n)) return false;
            }
            return true;
        }
    };
int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1,2,3}, {3,1,2}, {2,3,1}};
    bool ans = sol.checkValid(matrix);
    cout << "ans: " << ans << endl;
    return 0;
}