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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        // Actually this needs to be a stack as right parts from left will be processed first
        stack<TreeNode*> s;
        // What if I make another stack that only gets acted once q1 is emptied
        q.push(root);
        while (!q.empty() || !s.empty()) {
            TreeNode* node;
            if (!q.empty()) {
                node = q.front();
                q.pop();
            } else {
                node = s.top();
                s.pop();
            }

            if (!node) continue;
            ans.push_back(node->val);
            // Now I need to fix this somehow - recursive would be easiest
            q.push(node->left);
            s.push(node->right);
        }
        return ans;
    }
};

// I know DFS via recursion
// I know BFS via queue
