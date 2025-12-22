class Solution {
public:
    string intToRoman(int num) {
        int cnt = 0;
        string ans;
        while (num > 0) {
            // Push front wouldnt be very preferable
            int rem;
            int n = (num % 10) * pow(10, cnt);
            if (n >= 1000) {
                ans += "M" * (n / 1000);

            } else if (n >= 500) {
                rem = 1000 - n;
                if (rem == 100) {
                    ans += "CX";
                } else {
                    ans += "D" + "C" * ((n-500) / 100);
                }
            } else if (n >= 100) {
                rem = 500 - n;
                if (rem == 100) {
                    ans += "CD";
                } else {
                    ans += "C" * (n / 10);
                }
            } else if (n >= 50) {
                rem = 100 - n;
                if (rem == 10) {
                    ans += "XC";
                } else {
                    ans += "L" + "X" * ((n-50) / 10);
                }
            } else if (n >= 10) {
                rem = 50 - n;
                if (rem == 10) {
                    ans += "XL";
                } else {
                    ans += "X" * (n / 10);
                }
            } else if (n >= 5) {
                rem = 10 - n;
                if (rem == 1) {
                    ans += "IX";
                } else {
                    ans += "V" + "I" * ((n-10) / 10);
                }
            } else if (n >= 1) {
                rem = 10 - n;
                if (rem == 1) {
                    ans += "IV";
                } else {
                    ans += "I" * (n / 10);
                }

            num /= 10;
            cnt++;
        }
    }
};

// This just seems like a recursive problem
// 58 = 50 + 8
// 50 = L
// 8 = VIII
// Lakes make it small first
