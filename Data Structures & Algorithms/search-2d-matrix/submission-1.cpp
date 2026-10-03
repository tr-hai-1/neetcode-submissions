class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size(); 
        int l = 0;
        int r = m - 1;
        int findRow = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (matrix[m][0] <= target) {
                findRow = m;
                l = m + 1;
            } else
                r = m - 1;
        }
        l = 0;
        r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (matrix[findRow][m] < target)
                l = m + 1;
            else if (matrix[findRow][m] > target)
                r = m - 1;
            else
                return true;
        }
        return false;
    }
};
