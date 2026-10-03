class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;
        while (l <= r) {
            int m = l + (r - l) / 2;
            long long sum = 0;
            for (int x : piles)
                sum += 1LL * (x + m - 1) / m;
            if (sum <= h) {
                ans = m;
                r = m - 1;
            } else 
                l = m + 1;
        }
        return ans;
    }
};
