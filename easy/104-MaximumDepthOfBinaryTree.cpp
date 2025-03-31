#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
       int maxDepth(TreeNode* root) {
        int ans = 0;
        ans = maxDepthHelper(root, ans);
        return ans;
       }

       int maxDepthHelper(TreeNode* root, int depth) {
            if (root == nullptr) return depth;
            return max(maxDepthHelper(root->left, depth+1), maxDepthHelper(root->right, depth+1));
       }

       TreeNode* buildTree(const vector<int>& arr) {
        
        if (arr.empty() || arr[0] == -1) return nullptr;
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(arr[0]);
    
        q.push(root);
    
        int i=1;
        while (!q.empty() && i < arr.size()) {
            TreeNode* node = q.front();
            q.pop();
    
            if(i < arr.size() && arr[i] != -1) {
                node->left = new TreeNode(arr[i]);
                q.push(node->left);
            }
            i++;
            if(i < arr.size() && arr[i] != -1) {
                node->right = new TreeNode(arr[i]);
                q.push(node->right);
            }
            i++;
        }
        return root;
    
    }
};
int main() {
    Solution sol;
    vector<int> arr = {3,-1,20};
    TreeNode* root = sol.buildTree(arr);
    int ans = sol.maxDepth(root);
    cout << "ans: " << ans << endl;
    return 0;
}