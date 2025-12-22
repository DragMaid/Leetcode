class Solution {
public:
    int climbStairs(int n) {
        int cache[46];
        cache[0] = 1;
        cache[1] = 2;
        for (int i=2; i<n; i++) {
            cache[i] = cache[i-1] + cache[i-2];
        }
        return cache[n-1];
    }
};

/*
 * In order to know the number of possible steps that we can take at i
 * We must know how many possible steps it takes to reach stair
 * i-1 and i-2 cause from here we can continue to determine whether to take 1 or 2 steps

// This seems like a DP problem
// Number of ways to climb step i would be number number of ways climb step i-1 + min(rem, 1, 2)
// We know that the sum has to be equal to n 
// Since we aren't storing much this can also be done via recursion

/*
 * Example: n = 1 (1)
 * Example: n = 2 (2)
 * Example: n = 3 (3)
 * 1, 1, 1
 * 1, 2
 * 2, 1
 * Example: n = 4 (5)
 * 1,1,1,1 -> 3, 1
 * 1,1,2 -> 1, 3
 * 1,2,1 -> 3, 1
 * 2,1,1 -> 3, 1
 * 2,2 -> 2, 2
 * Example: n = 5 (8)
 * 1,1,1,1,1 -> 4,1
 * 1,1,1,2 -> 1, 4
 * 1,1,2,1 -> 1, 4
 * 1,2,1,1 -> 1, 4
 * 2,1,1,1 -> 1, 4
 * 1,2,2 -> 1, 4 
 * 2,1,2
 * 2,2,1
 */
