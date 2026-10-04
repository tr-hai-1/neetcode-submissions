class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int ans = 0;
        for (int price : prices) {
            mn = min(mn, price);
            ans = max(ans, price - mn);
        }
        return ans;
    }
};
