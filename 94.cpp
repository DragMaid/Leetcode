/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> values;
    vector<int> inorderTraversal(TreeNode* root) {
        getGroup(root);
        return values;
    }
private:
    void getGroup(TreeNode* root) {
        if (!root) return;
        getGroup(root->left);
        values.push_back(root->val);
        getGroup(root->right);
    }
};

// This kinda looks like a stack problem -> nope its not
// Im going to write a recursion function in order to do this
