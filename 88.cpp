class Solution {
public:
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int j = 0, i = 0;
    vector<int> ans;
    while (i < m || j < n) {
        int a = (i<m) ? nums1[i] : INT_MAX;
        int b = (j<n) ? nums2[j] : INT_MAX;
        if (a < b) {
            i++;
            ans.push_back(a);
        } else {
            j++;
            ans.push_back(b);
        }
    }
    nums1 = ans;
}
};
