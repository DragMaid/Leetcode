class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        unsigned int reversed = 0;
        int y = x;

        while (y > 0) {
            int rem = y % 10;
            reversed = reversed * 10 + rem;
            y /= 10;
        }
        return reversed == x;
    }
};

// For odd number: 3 -> [0] = 3 / 2 
// For even number: 4 -> [0, 1] = 4 /2
// After the string conversion solution would be the reverse int solution
// 121 -> 121 % 10 = 1 -> 121 / 10 % 10 = 2  -> 121 / 100 % 10 = 1
//
// For even numbers: 
// 10 -> 10 % 10 = 0 -> 10 / 10 = 1 -> 1 % 10 = 1 -> 10 + 0 = 10
// 1000 -> 0001
