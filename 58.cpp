class Solution {
public:
    int lengthOfLastWord(string s) {
        int start = 0; 
        int end = 0;
        bool l_already = false;
        for (int i=(int)s.length()-1; i >= 0; i--) {
            if (s[i] == ' ' && l_already) {
                start = i;
                break;
            } else if (s[i] != ' ' && !l_already) {
                l_already = true;
                end = i;
            }
        }
        return end - start;
    }
};
