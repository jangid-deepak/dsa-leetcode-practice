#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums = {3, -2, 1, 1};
    int n = nums.size();
    for(int i=0; i<n; i++) {
        cout << "(i + nums[i] % n + n)%n " << (i + nums[i] % n + n)%n<< endl;
    }
}
