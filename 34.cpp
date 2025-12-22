class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;

        int first = binarySearch(nums, l, r, target);
        if (first < 0) return {-1, -1};

        int start = first;
        int end = first;

        int s = binarySearch(nums, 0, first-1, target);
        while (s != -1) {
            start = min(start, s);
            s = binarySearch(nums, 0, s-1, target);
        }

        int e = binarySearch(nums, first+1, nums.size()-1, target);
        while (e != -1) { 
            end = max(e, end);
            e = binarySearch(nums, e+1, nums.size()-1, target);
        }

        return {start, end};
    }
private:
    int binarySearch(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;

            if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};

// The idea would be a binary search
// Where the value is first found
// perform 2 other binary search at found +- 1
// repeat until both sides return -1
