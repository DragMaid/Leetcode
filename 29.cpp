class Solution {
public:
    int divide(int dividend, int divisor) {
        // The only clamping scenario
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        long dvd = labs(dividend);
        long dvs = labs(divisor);
        long ans = 0;

        // Why this work is because we continuously increase by double x2
        // This speed up the speed
        // But also we still acconunt for odd situations like 2n + 1
        // Example: 9 / 3
        // then tmp would goes up to 6 (12 would be over kill)
        // ans = 2 (for now)
        // but (9-6) >= 3
        // So we do another round
        // This time m will just be 1 (no bit shift
        // So now ans = 2 + 1 = 3
        while (dvd >= dvs) {
            long tmp = dvs;
            long m = 1;
            while (tmp<<1 <= dvd) {
                tmp <<= 1;
                m <<= 1;
            }
            dvd -= tmp;
            ans += m;
        }

        // Using XOR operator
        int modifier = dividend > 0 ^ divisor > 0 ? -1 : 1;
        return ans * modifier;
    }
};

