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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTRec({0, nums.size()-1}, nums);
    }
private:
    TreeNode* sortedArrayToBSTRec(pair<int, int> se, vector<int>& nums) {
        //if (se.first < 0 || se.second >= nums.size()) return nullptr;
        if (se.first > se.second) return nullptr;
        int mid = (se.second + se.first) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTRec({se.first, mid-1}, nums);
        root->right = sortedArrayToBSTRec({mid+1, se.second}, nums);
        return root;
    }
};
