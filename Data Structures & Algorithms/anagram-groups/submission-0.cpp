class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const auto& str : strs) {
            int cnt[26] = {};
            for (char ch : str) {
                cnt[ch - 'a']++;
            }
            string key;
            for (int i = 0; i < 26; i++) {
                key += '#';
                key += to_string(cnt[i]);
            }
            mp[key].push_back(str);
        }
        vector<vector<string>> ans;
        for (const auto& [key, vec] : mp) {
            ans.push_back(move(vec));
        }
        return ans;
    }
};
