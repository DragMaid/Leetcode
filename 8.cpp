class Solution {
public:
int myAtoi(string s) {
    // 48 - 57 - (0 - 9)
    // 43 - (+)
    // 45 - (-)
    int start = -1;
    int end = -1;
    int f_d = -1;

    for (int i=0; i<(int)s.length(); i++) {
        bool spec = s[i] == ' ' || s[i] == '+' || s[i] == '-';
        // Handle special letters
        if ((start >= 0 || f_d >= 0) && spec) {
            // Drop if first digit has already been found
            end = i-1;
            break;
        } else if (spec) {
            if (i > 0 && (s[i-1] == '-' || s[i-1] == '+')) return 0;
            continue;
        }

        // Handle digit letters
        int ci = s[i] - '0';
        if (0 <= ci && ci <= 9) {
            if (ci == 0 && f_d < 0) f_d = i;
            else if (ci != 0 && start < 0) start = i;
        } 
        // Handle letters
        else {
            end = i-1;
            break;
        }
    }  
    if (start < 0) return 0;
    end = (end >= 0) ? end : s.length()-1;

    // Stoi wouldn't make it so now I need to do something else
    int mod = 1;
    if ((f_d > 0 && s[f_d-1] == '-') || (start > 0 && s[start-1] == '-'))
        mod = -1;

    string sans = s.substr(start, end-start+1);
    int ans = 0;
    for (int i=0; i<sans.length(); i++) {
        int n = (sans[i] - '0') * mod;
        if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && n > 7)) return INT_MAX;
        if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && n < -8)) return INT_MIN;
        ans = ans * 10 + n;
    }

    return ans;
}
};
