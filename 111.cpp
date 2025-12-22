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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int depth = 1;
        if (!root) return 0;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i=0; i<levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                // For each node at the current level
                if (!node->left && !node->right) return depth;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};

// This will be an implementation using BFS
