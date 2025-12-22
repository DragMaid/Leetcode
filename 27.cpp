class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> tmp;
        for (auto it=nums.begin(); it!=nums.end(); it++) {
            if (*it != val) tmp.push_back(*it);
        }
        nums = tmp;
        return (int)nums.size();
    }
};
