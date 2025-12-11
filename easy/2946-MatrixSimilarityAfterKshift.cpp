#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void display(vector<vector<int>>& mat) {     
        int m = mat.size();
        int n = mat[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                cout << " " << mat[i][j];
            }
            cout << endl;
        }

    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        cout << "display befor trans" << endl;
        display(mat);
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                // even
                int index;
                if (i%2 == 0) {
                    index = (j+k)%n;
                } else {
                    index = abs(j-k)%n;
                }

                int t = mat[i][index];
                mat[i][index] = mat[i][j];
                mat[i][j] = t;
            }
        }
        cout << "display after trans" << endl;
        display(mat);
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    bool ans = sol.areSimilar(mat, 1);
    cout << "ans " << ans << endl;
    return 0;
};
