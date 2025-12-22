/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans; 
        stack<TreeNode*> heads;
        stack<TreeNode*> paths;
        heads.push(root);

        if (!root) return {};
        while (!heads.empty()) {
            TreeNode* current = heads.top();
            
            // If all its sub trees are processed then add itself
            if (!paths.empty() && paths.top() == current) {
                ans.push_back(current->val);
                paths.pop();
                heads.pop();
            } else {
                paths.push(current);
                if (current->right) heads.push(current->right);
                if (current->left) heads.push(current->left);
            }
        }
        return ans;
    }
};
