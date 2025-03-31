#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}

};

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

// // Depth-First Traversals (DFS)
// // root -> left -> right
// void preOrderTraversal(TreeNode* root) {
//     if (root == nullptr) return;
//     cout << "val: " << root->val << endl;
//     inOrderTraversal(root->left);
//     inOrderTraversal(root->right);

// };
// // left-> root -> right
// void inOrderTraversal(TreeNode* root) {
//     if (root == nullptr) return;
//     inOrderTraversal(root->left);
//     cout << "val: " << root->val << endl;
//     inOrderTraversal(root->right);

// };

// // left -> right -> root
void postOrderTraversal2(TreeNode* root, vector<int>& arr) {
    if (root == nullptr) return;
    postOrderTraversal2(root->left, arr);
    postOrderTraversal2(root->right, arr);
    arr.push_back(root->val);

};

// Breadth-First-Traversal (BFS)

void levelOrderTraversal(TreeNode* root, vector<int>& arr) {
    if (root == nullptr) return;
    queue <TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        // cout << "val: " << root->val << endl;
        arr.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    
};

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    postOrderTraversal2(root, ans);
    return ans;
};

// [1,2,3,4,5,null,8,null,null,6,7,9]

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, -1, 8, -1, -1, 6, 7, 9};

    TreeNode* root = buildTree(arr);

    vector<int> ans = postorderTraversal(root);
    for (int i=0; i<ans.size(); i++) {
        cout << "val: " << ans[i] << endl;
    }

    return 0;
};