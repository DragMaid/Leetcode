class Solution {
public:
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    int n = nums.size();
    for (int i=0; i<n-3; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;

        // Add early termination
        long long min_i = (long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3];
        if (min_i > target) break;
        long long max_i = (long long)nums[i] + nums[n-1] + nums[n-2] + nums[n-3];
        if (max_i < target) continue;


        for (int j=i+1; j<n-2; j++) {
            if (j > i+1 && nums[j] == nums[j-1]) continue;

            // Add early termination
            long long min_j = (long long)nums[i] + nums[j] + nums[j+1] + nums[j+2];
            if (min_j > target) break;
            long long max_j = (long long)nums[i] + nums[j] + nums[n-1] + nums[n-2];
            if (max_j < target) continue;

            int l = j+1;
            int h = n-1;
            while (l < h) {
                long long candidate = (long long)nums[i] + nums[j] + nums[l] + nums[h];
                if (candidate < target) l++;
                else if (candidate > target) h--;
                else {
                    ans.push_back({nums[i], nums[j], nums[l], nums[h]});
                    // This is a smart trick
                    l++; h--;
                    while (l < h && nums[l] == nums[l-1]) l++;
                    while (l < h && nums[h] == nums[h+1]) h--;
                }
            }
        }
    }
    return ans;
}
};

// Maybe ill implement a four pointer solution ?
// This unique characteristic is annoying
// Record the last occurence and shift till we are out of it

