class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(ans.begin(), ans.end());
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
            // Why is it the larger condition ?
            if (idx > i && nums[idx] == nums[i]) continue;
            swap(nums[idx], nums[i]);
            generate(ans, nums, idx+1);
            // Since there are duplicates so I cant just swap them back here
            //swap(nums[idx], nums[i]);
        }
        for (int i=nums.size()-1; i>idx; --i) 
            swap(nums[pos], nums[i]);
    }
};

// I feel like this works for both cases
// Maybe if we are swapping the same shit then don't
//
// The idea is to fix one position at a time 
// Example: [1,2,3]
// idx = 0
// 1,2,3 -> gen(idx=1) -> 1,2,3 | 1,3,2 -> gen(idx=2) -> same as before -> gen(idx=3) -> return all;
// 2,1,3 -> 2,1,3 | 2,3,1
// 3,2,1 -> 3,2,1 | 3,1,2
// In total there are now 6 of them
