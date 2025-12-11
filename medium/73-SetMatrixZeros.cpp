#include <iostream>
#include <vector>

using namespace std;


class Solution {
    public:
    void setZeroes(vector<vector<int>>& matrix) {
        // find zeros
        vector<int> zeros(matrix.size(), -1);
        bool first = true;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix.size(); j++) {
                if (matrix[i][j] == 0) {
                    zeros[i] = 0;
                }
            }
        }

        // zeros
        for(int num: zeros) {
            cout << " " << num;
        }
        cout << endl;
    }
};


int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 0}};

    Solution sol;
    sol.setZeroes(matrix);
    for(vector<int> row: matrix) {
        for(int cell: row) {
            cout << " " << cell;
        }
        cout << endl;
    }
    return 0;
}
