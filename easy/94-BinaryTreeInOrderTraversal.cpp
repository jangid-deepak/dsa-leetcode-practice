#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}

};


class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> ans;
            inorderTraversalHelper(root, ans);
            return ans;
        }

        void inorderTraversalHelper(TreeNode* root, vector<int>& ans) {
            if (root == nullptr) return;
            if (root->left) inorderTraversalHelper(root->left, ans);
            ans.push_back(root->val);
            if (root->right) inorderTraversalHelper(root->right, ans);
        }

        TreeNode* buildTree(vector<int> nums) {
            TreeNode* root = new TreeNode(nums[0]);
            queue<TreeNode*> q;
            q.push(root);
            int i=1;
            while (!q.empty() && i < nums.size()) {
                TreeNode *root = q.front();
                q.pop();
                if (nums[i] != -1 && i < nums.size()) {
                    root->left = new TreeNode(nums[i]);
                    q.push(root->left);
                }
                i++;
                if (nums[i] != -1 && i < nums.size()) {
                    root->right = new TreeNode(nums[i]);
                    q.push(root->right);
                }
                i++;
            }
            return root;
        }
    };
int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4,5,-1,8,-1,-1,6,7,9};
    TreeNode* root = sol.buildTree(nums);
    vector<int> ans = sol.inorderTraversal(root);
    for(int a: ans) {
        cout << " " << a ;
    }
    cout << endl;
    return 0;
}