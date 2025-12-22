class Solution {
public:
    string countAndSay(int n) {
        return countAndSayRec(n);
    }
private:
    string countAndSayRec(int n) {
        if (n == 1) return "1";

        string ans = countAndSayRec(n-1);
        for (int i=0; i<(int)ans.size(); i++) {
            int count = 0;
            char c = ans[i];
            while (ans[i] == c && i<(int)ans.size()) {
                i++;
                count++;
            }
            ans.push_back(char(count)+0);
            ans.push_back(char(c)+0);
        }

        return ans;
    }
};

