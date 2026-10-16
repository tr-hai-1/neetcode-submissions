class Solution {
public:
    int func(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            if (i == 0)
                dp[i] = nums[i];
            else if (i == 1)
                dp[i] = max(nums[i], dp[i - 1]);
            else
                dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp.back();
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> first(nums.begin(), nums.end() - 1);
        vector<int> second(nums.begin() + 1, nums.end());
        return max(func(first), func(second));
    }
};
