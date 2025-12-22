class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = (int)nums.size() - 1;
        while (start <= end) {
            int k = start + (end - start) / 2;
            if (nums[k] > target) end = k - 1;
            else if (nums[k] < target) start = k + 1;
            else return k;
        }

        return start;
    }
};

// The plan would be to implement a binary tree
