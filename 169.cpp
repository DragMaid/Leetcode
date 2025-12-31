class Solution {
public:
int majorityElement(vector<int>& nums) {
    int n = nums.size() / 2;
    unordered_map<int, int> um;
    for (const int i : nums) {
        um[i]++;
        if (um[i] > n) return i;
    }
    return -1;
}
};
