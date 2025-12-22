class Solution {
public:
vector<char> ntt[10] = {
    {}, {},
    {'a','b','c'},
    {'d','e','f'},
    {'g','h','i'},
    {'j','k','l'},
    {'m','n','o'},
    {'p','q','r','s'},
    {'t','u','v'},
    {'w','x','y','z'}
};

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    combineLetters(digits, "", ans);
    return ans;
}

private:
void combineLetters(string& digits, string& last, vector<string>& ans) {
    char d = digits[0];
    int di = (int)(d - '0');
    vector<char> cs = ntt[di];
    for (const char c : cs) {
        if (digits.length() == 1) {
            ans.push_back(last + c);
            continue;
        } else {
            combineLetters(digits.substr(1, digits.length()-1), last + c);
        }
    }
}
};
