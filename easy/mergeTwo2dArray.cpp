
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
	{
		int m = nums1.size();
		int n = nums2.size();
		int i = 0, j = 0;
		vector<vector<int>> res;
		while (i < m || j < n)
		{
			// nums2 remains
			if (i == m)
			{
				for (int index = j; index < n; index++)
				{
					res.push_back({nums2[j][0], nums2[index][1]});
					j++;
				}
				break;
			}
			// nums1 remains
			if (j == n)
			{
				for (int index = i; index < m; index++)
				{
					res.push_back({nums1[i][0], nums1[index][1]});
					i++;
				}
				break;
			}
			// equal
			if (nums1[i][0] == nums2[j][0])
			{
				res.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
				i++;
				j++;
			}
			else if (nums1[i][0] < nums2[j][0])
			{
				res.push_back({nums1[i][0], nums1[i][1]});
				i++;
			}
			else if (nums1[i][0] > nums2[j][0])
			{
				res.push_back({nums2[j][0], nums2[j][1]});
				j++;
			}
		}

		return res;
	}

	void printArray(vector<vector<int>> &nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			cout << i << " " << "[" << nums[i][0] << " " << nums[i][1] << "]" << endl;
		}
		return;
	}
};

int main()
{
	Solution sol;
	// vector<vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}};
	// vector<vector<int>> nums2 = {{1, 4}, {3, 2}, {4, 1}};
	vector<vector<int>> nums1 = {{2, 4}, {3, 6}, {5, 5}};
	vector<vector<int>> nums2 = {{1, 3}, {4, 3}};
	vector<vector<int>> res = sol.mergeArrays(nums1, nums2);
	sol.printArray(res);
	return 0;
}
