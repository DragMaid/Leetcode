class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> cnt;
        for(char c : s) cnt[c]++;

        int n = s.length();
        int ans = n;
        int k = n / 4;
        int i = 0;

        for (int j=0; j<n; j++) {
            cnt[s[j]]--; // Removes the letter the substring holds
            while (i < n && cnt['Q'] <= k && cnt['W'] <= k && cnt['E'] <= k && cnt['R'] <= k) {
                ans = min(ans, j-i+1);
                cnt[s[i]]++; // Moves left pointer by 1
                i++;
            }
        }
        return ans;
    }
};
