class Solution {
public:
int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int cache[128];
    memset(cache, 0xFF,sizeof(cache));

    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            char c = s[j];
            if (cache[c] != -1) {
                int new_i = min(n, cache[c] + 1);
                // Remove all the old occurences
                for (int k=i; k<new_i; k++)
                    cache[s[k]] = -1;
                i = new_i;
            } 
            cache[c] = j;
            ans = max(ans, j-i+1);
        }
    }
    return ans;
}
};

// Im smelling a bit of sliding windows
// I may also consider using caching
