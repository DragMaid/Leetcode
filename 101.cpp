class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return checkGroup(root->left, root->right);
    }
private:
    bool checkGroup(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return ((p->val == q->val) && checkGroup(p->left, q->right) && checkGroup(p->right, q->left));
    } 
};

