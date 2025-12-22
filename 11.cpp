class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_v = 0;
        int i=0, j=height.size()-1;
        while (i < j) {
            int vol = min(height[i], height[j]) * (j-i);
            max_v = max(vol, max_v);
            if (height[i] < height[j]) i++;
            else j--;
        }
        return max_v;
    }
};


// What if we do a sliding window but the length is determined based on the max

