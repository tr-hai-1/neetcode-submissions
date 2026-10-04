class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        vector<int> cnt(26, 0);
        int l = 0;
        int mxf = 0;
        for (int r = 0; r < (int)s.size(); r++) {
            cnt[s[r] - 'A']++;
            mxf = *max_element(cnt.begin(), cnt.end());
            while (r - l + 1 - mxf > k) {
                cnt[s[l] - 'A']--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
