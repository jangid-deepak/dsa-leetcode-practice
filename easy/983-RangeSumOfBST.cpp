#include <iostream>


struct TreeNode {
    int val;
   TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        return helper(root, low, high, ans);
    }

    int helper(TreeNode* root, int low, int high, int& ans) {
        if (root == NULL) return 0;
        if (root->val >= low && root->val <= high) {
            ans += root->val;
        }
        ans += helper(root->left, low, high, ans);
        ans += helper(root->right, low, high, ans);
        return ans;
    }
};
