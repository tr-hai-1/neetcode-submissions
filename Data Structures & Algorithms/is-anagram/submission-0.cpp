class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mpS;
        for (char ch : s) {
            mpS[ch]++;
        }
        map<char, int> mpT;
        for (char ch : t) {
            mpT[ch]++;
        }
        return (mpS == mpT);
    }
};
