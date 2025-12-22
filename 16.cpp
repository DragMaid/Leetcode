class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int ans;
        int min_diff = INT_MAX;
        for (int i=0; i<nums.size()-2; i++) {
            int l = i+1;
            int h = nums.size()-1;
            while (l < h) {
                int candidate = nums[i] + nums[l] + nums[h];
                if (candidate < target) l++;
                else if (candidate > target) h--;
                else return candidate;

                int diff = abs(candidate-target);
                if (diff < min_diff) {
                    min_diff = diff;
                    ans = candidate;
                }
            }
        }
        return ans;
    }
};
