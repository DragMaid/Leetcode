class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> unique;       
        for (int num : nums) unique.insert(num);
        nums.clear();
        nums.assign(unique.begin(), unique.end());
        return (int)nums.size();
    }
};
