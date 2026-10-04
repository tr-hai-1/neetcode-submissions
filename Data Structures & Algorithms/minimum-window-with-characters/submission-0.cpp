class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size() || t.empty())
            return "";
        unordered_map<char, int> cnt, window;
        for (char ch : t) {
            cnt[ch]++;
        }
        int have = 0, need = cnt.size();
        pair<int, int> pos = {-1, -1};
        int resSize = INT_MAX;
        int l = 0;
        for (int r = 0; r < (int)s.size(); r++) {
            char cur = s[r];
            window[cur]++;
            if (cnt.count(cur) && cnt[cur] == window[cur])
                have++;
            while (have == need) {
                if (r - l + 1 < resSize) {
                    resSize = r - l + 1;
                    pos = {l, r};
                }
                window[s[l]]--;
                if (cnt.count(s[l]) && window[s[l]] < cnt[s[l]])
                    have--;
                l++;
            }
        }
        if (resSize == INT_MAX)
            return "";
        string res;
        for (int i = pos.first; i <= pos.second; i++)
            res += s[i];
        return res;
    }
};
