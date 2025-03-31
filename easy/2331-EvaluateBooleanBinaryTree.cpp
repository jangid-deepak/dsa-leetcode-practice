#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool evaluateTree(TreeNode *root)
    {
        if (root->left == nullptr && root->right=nullptr) {
            return root->val;            
        }

        bool evaluateTreeLeftSubTree = evaluateTree(root->left);
        bool evaluateTreeRightSubTree = evaluateTree(root->right);

        
        if (root->val == 2) {
            return evaluateTreeLeftSubTree | evaluateTreeRightSubTree;
        } else {
            return evaluateTreeLeftSubTree & evaluateTreeRightSubTree;
        }
    }
    


    bool operationHelper(int val, int left, int right) {
        if (val == 3) {
            return left && right;
        } else {
            return left || right;
        }
    }

    void travarsal(TreeNode *root)
    {
        if (root == nullptr)
            return;
        if (root->right)
            travarsal(root->right);
        if (root->left)
            travarsal(root->left);
        cout << root->val << endl;
    }

    TreeNode *buildTree(vector<int> &arr)
    {
        if (arr.empty() || arr[0] == -1)
            return nullptr;

        queue<TreeNode *> q;
        TreeNode *root = new TreeNode(arr[0]);

        q.push(root);
        int i = 1;
        while (!q.empty() && i < arr.size())
        {
            TreeNode *node = q.front();
            q.pop();

            if (i < arr.size() && arr[i] != -1)
            {
                node->left = new TreeNode(arr[i]);
                q.push(node->left);
            }
            i++;
            if (i < arr.size() && arr[i] != -1)
            {
                node->right = new TreeNode(arr[i]);
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
    // Print Tree Function (Sideways)
    void printTree(TreeNode *root, int space = 0, int gap = 5)
    {
        if (root == nullptr)
            return;

        space += gap; // Increase spacing for next level

        // Print right child first (to appear at the top)
        printTree(root->right, space);

        // Print current node
        cout << endl;
        for (int i = gap; i < space; i++)
            cout << " ";
        cout << root->val << "\n";

        // Print left child
        printTree(root->left, space);
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {2, 1, 3, -1, -1, 0, 1};
    TreeNode *root = sol.buildTree(arr);
    sol.travarsal(root);
    // sol.printTree(root);
    // cout << "ans: " <<  << endl;
    return 0;
}