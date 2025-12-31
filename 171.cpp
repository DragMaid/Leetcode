class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        int cnt = 0;
        for (int i=columnTitle.size()-1; i >= 0; i--) {
            int num = columnTitle[i] - 'A' + 1;
            res += pow(26, cnt) * num;
            cnt++;
        }
        return res;
    }
};

// AA = 26 ** 1 * 1 + 26 ** 0 * 1
