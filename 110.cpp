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
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
private:
    int checkHeight(TreeNode* root) {
        if (!root) return 0;

        int leftCheck = checkHeight(root->left);
        if (leftCheck == -1) return -1;

        int rightCheck = checkHeight(root->right);
        if (rightCheck == -1) return -1;

        if (abs(rightCheck - leftCheck) > 1) return -1;
        return 1 + max(leftCheck, rightCheck);
    }
};
