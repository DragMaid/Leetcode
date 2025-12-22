class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> um = {{']', '['}, {'}', '{'}, {')', '('}};
        stack<char> sta;

        for (char c : s) {
            if (um.find(c) == um.end()) sta.push(c);
            else if (!sta.empty() && um[c] == sta.top()) sta.pop();
            else return false;
        }

        return sta.empty();
    }
};
