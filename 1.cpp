class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;

        // Insert all values as key with thir indexes and check behind as we go
        for (int i=0; i<nums.size(); i++) {
            int rem = target - nums[i];
            if (ump.find(rem) != ump.end()) 
                return {ump[rem], i};
            ump.insert({nums[i], i});
        }

        return {};
    }
};

// [2, 7, 11, 15], target = 9
// Solution 1: Sliding window way -> takes n(n-1) -> very bad
// Solution 2: sort then use binary search -> nlogn + nlogn
// Solution 3: saving the state all into an array -> check for appearance -> n + n
// Assumption: that all values are within int range
