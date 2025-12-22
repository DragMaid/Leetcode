class Solution {
public:
string convert(string s, int numRows) {
    string ans;
    int n = s.length();

    if (numRows == 1 || n <= numRows) return s;
    if (numRows == 2) {
        for (int m=0; m<2; m++) {
            int t = m + 2;
            if (m<n) ans.push_back(s[m]);
            while (t < n) {
                ans.push_back(s[t]);
                t += 2;
            }
        }
        return ans;
    }

    // First for the first row
    int f = 0;
    while (f < n) {
        ans.push_back(s[f]);
        f += (numRows - 1) * 2;
    }

    // For the middle rows
    for (int i=1; i<numRows-1; i++) {
        int j = i;
        if (i<n) ans.push_back(s[i]);

        j += (numRows - 1) * 2 - 2*i;
        while (j < n) {
            ans.push_back(s[j]);
            if (j + 2*i < n) 
                ans.push_back(s[j+2*i]);
            j += (numRows - 1) * 2;
        }
    }

    // First for the last row
    int k = numRows - 1;
    while (k < n) {
        ans.push_back(s[k]);
        k += (numRows - 1) * 2;
    }

    return ans;
}
};
