#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Spreadsheet {

    private:
        vector<vector<int>> gird;
    public:
        Spreadsheet(int rows) {
            gird.resize(26, vector<int>(rows, 0));
        }
        
        void setCell(string cell, int value) {
            int col = cell[0] - 'A';       // Convert 'A'-'Z' to 0-25
            int row = stoi(cell.substr(1)) - 1;  // Convert 1-based to 0-based
            if (row >= 0 && row < grid[0].size()) {
                grid[col][row] = value;
            }        
        }
        
        void resetCell(string cell) {
            int col = cell[0] - 'A';
            int row = stoi(cell.substr(1)) - 1;
            if (row >= 0 && row < grid[0].size()) {
                grid[col][row] = 0;
            }
        }
        
        int getCellValue(string cell) {
            int col = cell[0] - 'A';
            int row = stoi(cell.substr(1)) - 1;
            if (row >= 0 && row < grid[0].size()) {
                return grid[col][row];
            }
            return 0;  
            }
        
        int getValue(string formula) {
            size_t pos = formula.find('+');
            if (pos == string::npos) return 0;  // Ensure valid format
    
            string x = formula.substr(1, pos - 1);
            string y = formula.substr(pos + 1);
            int x1, y1;
    
            try {
                x1 = stoi(x);
            } catch (...) {
                x1 = getCellValue(x);
            }
    
            try {
                y1 = stoi(y);
            } catch (...) {
                y1 = getCellValue(y);
            }
    
            return x1 + y1;
        }
    };
    
int main() {    
    Spreadsheet* sheet = new Spreadsheet(25);
    sheet->setCell("B24", 66688);
    sheet->resetCell("O15");
    return 0;
}