class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;

            if (nums[mid] >= nums[l]) {
                if (nums[mid] > target && nums[l] <= target) r = mid-1;
                else l = mid+1;
            } else {
                if (nums[mid] < target && nums[r] >= target) l = mid+1;
                else r = mid-1;
            }
        }

        return -1;
    }
};

// The idea would be similar to a binary search
// But we must have conditional sort towards to
// the sorted part that contains the target value
