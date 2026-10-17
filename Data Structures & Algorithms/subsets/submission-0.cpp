class Solution {
public:
    void backtracking (int step, int n, vector<int>& nums, vector<int>& cur, vector<vector<int>>& res) {
        if (step == n) {
            res.push_back(cur);
            return;
        }
        backtracking(step + 1, n, nums, cur, res);
        cur.push_back(nums[step]);
        backtracking(step + 1, n, nums, cur, res);
        cur.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> cur;
        vector<vector<int>> res;
        backtracking(0, n, nums, cur, res);
        return res;
    }
};
