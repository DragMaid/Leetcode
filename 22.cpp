class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfsGen(0,0,"",n,ans);
        return ans;
    }
private:
    void dfsGen(int l, int r, string last, int n, vector<string>& ans) {
        if (last.size() == n * 2) ans.push_back(last);
        if (l < n) dfsGen(l+1, r, last + '(', n, ans);
        if (l > r) dfsGen(l, r+1, last + ')', n, ans);
    }
};

// This time I will perform a DFS so I open when possible
// And add a corresponding close every time possible
