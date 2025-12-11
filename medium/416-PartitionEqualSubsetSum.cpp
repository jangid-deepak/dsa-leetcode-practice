#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool canPartition(vector<int> &nums)
  {

    return true;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 5, 11, 5};
  bool ans = sol.canPartition(nums);
  cout << "ans: " << ans << endl;
}
