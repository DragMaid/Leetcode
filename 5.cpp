class Solution {
public:
string longestPalindrome(string s) {
    int n = s.length(); 
    
    // Formatting string so its always odd
    string fs;
    fs.push_back('$');
    for (char c : s) {
        fs.push_back('#');
        fs.push_back(c);
    }
    fs.push_back('#');
    fs.push_back('^');

    n = fs.length();
    vector<int> rad(n, 0);
    int l = 0;
    int r = 0;
    int mlen = 1;
    for (int i=1; i<n-1; i++) {
        if (i < r) {
            int mirror = l + r - i;
            rad[i] = min(r - i, rad[mirror]);
        }

        while (fs[i+1+rad[i]] == fs[i-1-rad[i]])
            ++rad[i];

        if (rad[i] * 2 + 1 > mlen) {
            r = i + rad[i];
            l = i - rad[i];
            mlen = rad[i] * 2 + 1;
        }
    }

    return s.substr((l+1)/2-1, rad[(r+l)/2]);
}
};
