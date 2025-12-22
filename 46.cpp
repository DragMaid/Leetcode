class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        generate(ans, nums, 0);
        return ans;
    }
private:
    void generate(
            vector<vector<int>>& ans,
            vector<int>& nums,
            int idx) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i=idx; i<nums.size(); i++) {
            swap(nums[idx], nums[i]);
            generate(ans, nums, idx+1);
            swap(nums[idx], nums[i]);
        }
    }
};

// The idea is to fix one position at a time 
// Example: [1,2,3]
// idx = 0
// 1,2,3 -> gen(idx=1) -> 1,2,3 | 1,3,2 -> gen(idx=2) -> same as before -> gen(idx=3) -> return all;
// 2,1,3 -> 2,1,3 | 2,3,1
// 3,2,1 -> 3,2,1 | 3,1,2
// In total there are now 6 of them
