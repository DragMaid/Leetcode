class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans{{}};
        sort(nums.begin(), nums.end());
        generate(nums, {}, ans, 0);
        return ans;
    }
private:
    void generate(vector<int>& nums, vector<int> last, vector<vector<int>>& ans, int start) {
        int old = -11;
        for (int i=start; i<nums.size(); i++) {
            if (nums[i] == old) continue;
            vector<int> tmp = last;
            tmp.push_back(nums[i]);
            ans.push_back(tmp);
            generate(nums, tmp, ans, i+1);
            old = nums[i];
        }
    }
};

// Lets say for [1,1,2,2]
// I still want to include 1
// But I will not include 1 as start of next iteration
// What if I check in last if the current is same if not then continue
//
// Then it would be
// 1,1,2,2
// 1,2,2
// 1,2
//
// 1,2,2
// 1,2
