class Solution {
public:
bool isPalindrome(string s) {
    int low = 0;
    int high = s.length() - 1;
    //int length = 0;
    while (low < high) {
        int l_c = (int)tolower(s[low]);
        while (!isAphaNum(l_c) && low < s.length()-1)
            l_c = (int)tolower(s[++low]);

        int h_c = (int)tolower(s[high]);
        while (!isAphaNum(h_c) && high > 0)
            h_c = (int)tolower(s[--high]);

        //cout << "Comparing: " << (char)l_c  << " : " << (char)h_c << endl;
        if (isAphaNum(l_c) && isAphaNum(h_c) && l_c != h_c) return false;
        //length++;
        low++;
        high--;
    }
    return true;
}
private:
    bool isAphaNum(int n) {
        return ((97 <= n && n <= 122) || (48 <= n && n <= 57));
    }
};

// Ill do the 2 separate steps first
// Then ill try to combine them in 1 loop

    //bool isPalindrome(string s) {
        //string format;
        //for (auto& c : s) {
            //c = tolower(c);
            //int a_c = (int)c;
            //// Its alpha numeric
            //if ((97 <= a_c && a_c <= 122) || (48 <= a_c && a_c <= 57)) 
                //format.push_back(c);
        //}
    //}
