class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMn = 1, curMx = 1;
        for (int num : nums) {
            int first = curMx * num;
            int second = curMn * num;
            curMx = max(max(first, second), num);
            curMn = min(min(first, second), num);
            res = max(res, curMx);
        }
        return res;
    }
};
