class Solution {
public:
    int strStr(string haystack, string needle) {
        int h_s = haystack.size();
        int n_s = needle.size();
        for (int i=0; i<h_s-n_s+1; i++) {
            string can = haystack.substr(i, n_s);
            if (can == needle) return i;
        }
        return -1;
    }
};

// When its only 1 letter: 'a' and 'a'
