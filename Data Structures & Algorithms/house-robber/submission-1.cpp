class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0)
                dp[i] = nums[i];
            else if (i == 1)
                dp[i] = max(nums[i], dp[i - 1]);
            else
                dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
            mx = max(mx, dp[i]);
        }
        return mx;        
    }
};
