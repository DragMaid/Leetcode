class Solution {
public:
string convertToTitle(int columnNumber) {
    string res;
    while (columnNumber > 0) {
        columnNumber--;
        int c_dec = columnNumber % 26;
        res.push_back((char)(c_dec + 65));
        columnNumber /= 26;
    }
    reverse(res.begin(), res.end());
    return res;
}
};
