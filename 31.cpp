class Solution {
public:
void nextPermutation(vector<int>& nums) {
    int swapped = -1;
    for (int i=nums.size()-2; i >= 0; i--) {
        int min_diff = INT_MAX;
        int r_idx = i;
        for (int j=i+1; j < nums.size(); j++) {
            if (nums[j] > nums[i] && nums[j]-nums[i] < min_diff) {
                min_diff = nums[j] - nums[i];
                r_idx = j;
            }
        }
        // Perform swap if a candidate was found
        if (r_idx != i) {
            int tmp = nums[i];
            nums[i] = nums[r_idx];
            nums[r_idx] = tmp;
            swapped = i;
            break;
        }
    }

    if (swapped >= 0) {
        
    }
    // Problem is making it as small as possible after first swap
    // Its technically just sorting the array after the swap
    if (swapped >= 0) sort(nums.begin()+swapped+1, nums.end());

    if (swapped < 0) sort(nums.begin(), nums.end());
}
};

// The idea would be to search backward for a value that is larger and nearest to itself
// If till the end and no shit is found (the input is largest then sort the array)
