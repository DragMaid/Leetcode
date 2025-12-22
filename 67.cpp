class Solution {
public:
string addBinary(string a, string b) {
    string ans{""};
    int ia = a.length()-1;
    int ib = b.length()-1;

    int carry = 0;
    while (ia >= 0 || ib >= 0 || carry) {
        if (ia >= 0) carry += a[ia--] - '0'; 
        if (ib >= 0) carry += b[ib--] - '0';

        // Using to_string is very slow
        // Pre-pending is slower than appending
        ans += '0' + carry % 2;
        carry = (int)(carry / 2);
    }
    // So reverse in the end instead
    reverse(ans.begin(), ans.end());
    return ans;
}
};

