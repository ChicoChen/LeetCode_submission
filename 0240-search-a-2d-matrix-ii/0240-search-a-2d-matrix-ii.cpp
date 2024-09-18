class Solution {
public:
    // refer to solution
    int m, n;
    bool subSearch(const vector<vector<int>>& matrix, const int target, int i,
                   int j) {
        if (i >= m || j < 0)
            return false;

        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] < target)
            i++;
        else
            j--;
        return subSearch(matrix, target, i, j);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix.size(), n = matrix[0].size();
        return subSearch(matrix, target, 0, n - 1);
    }
};