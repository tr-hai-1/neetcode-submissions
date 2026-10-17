class Solution {
public:
    void backtracking(int step, int target, vector<int>& nums, vector<int>& cur, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0 || step >= nums.size()) return;
        cur.push_back(nums[step]);
        backtracking(step, target - nums[step], nums, cur, res);
        cur.pop_back();
        backtracking(step + 1, target, nums, cur, res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        vector<vector<int>> res;
        backtracking(0, target, nums, cur, res);
        return res;   
    }
};
