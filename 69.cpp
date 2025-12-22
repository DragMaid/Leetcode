class Solution {
public:
int mySqrt(int x) {
    int left = 1;
    int right = x / 2;
    int center;
    if (x == 1) return 1;
    while (left <= right) {
        center = (left + right) / 2;
        int p = center * center;
        if (p < x) {
            left = center + 1;
        } else if (p > x) {
            right = center - 1;
        } else {
            return center;
        }
    }
    if (center * center > x) center--;
    return center;
}
};

// I am going to implement like a binary search
