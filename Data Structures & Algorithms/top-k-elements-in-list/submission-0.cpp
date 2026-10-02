class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<vector<int>> freq(nums.size() + 1);
        for (int x : nums) {
            mp[x]++;
        }
        for (const auto& [x, y] : mp) {
            freq[y].push_back(x);
        }
        vector<int> sol;
        for (int i = freq.size() - 1; i >= 0; i--) {
            for (int n : freq[i]) {
                sol.push_back(n);
                if (sol.size() == k)
                    return sol;
            }
        }
        return sol;
    }
};
