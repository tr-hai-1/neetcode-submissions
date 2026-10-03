class Solution {
public:
    bool alphanumeric(char ch) {
        if (ch - 'a' >= 0 && ch - 'a' <= 25)
            return true;
        if (ch - 'A' >= 0 && ch - 'A' <= 25)
            return true;
        if (ch - '0' >= 0 && ch - '0' <= 9)
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (!alphanumeric(s[l])) {
                l++;
                continue;
            }
            if (!alphanumeric(s[r])) {
                r--;
                continue;
            }
            if (tolower(s[l]) != tolower(s[r]))
                return false;
            r--;
            l++;
        }
        return true;
    }
};
