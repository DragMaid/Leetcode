class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans{{}};
        generate(nums, ans, {}, 0);
        return ans;
    }
private:
    void generate(
            vector<int>& nums,
            vector<vector<int>>& ans,
            vector<int> last,
            int start) {
        for (int i=start; i<nums.size(); i++) {
            vector<int> tmp = last;
            tmp.push_back(nums[i]);
            ans.push_back(tmp);
            generate(nums, ans, tmp, i+1); 
        }
    }
};

