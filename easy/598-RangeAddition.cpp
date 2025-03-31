#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        int maxCount(int m, int n, vector<vector<int>>& ops) {
            int k = ops.size();
            int col = n, row = m;
            for(int i=0; i<k; i++) {
                int l = ops[i][0];
                int r = ops[i][1];
                col = min(col, r);
                row = min(row, l);

            }

            return col*row;
        }

        

        void print(vector<vector<int>> & arr, int m, int n) {
            for(int i=0; i<m; i++) {
                for(int j=0; j<n; j++) {
                    cout << arr[i][j] << " ";
                 }
                 cout << endl;
            }
        }

};
int main() {
    Solution sol;
    vector<vector<int>> ops =  {};
    int ans = sol.maxCount(3, 3, ops); 
    cout << "ans: "<< ans << endl;
    return 0;
}