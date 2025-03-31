#include <iostream>
#include <vector>

using namespace std;


class QuickSort {
    public:
        void quickSortAlgo() {

        }

        void findSum(vector<int>& nums) {
            if (nums.size() == 1) {
                return nums[0]
            }
            return findSum(nums) + nums[0];
        }
}


void quickSort() {
    cout << "quick sort calling..." << endl;
}

int main() {

    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    quickSort();
    return 0;
}