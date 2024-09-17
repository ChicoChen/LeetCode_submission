class Solution {
public:
    int m, n;
    //binary search
    //todo: optimize(only beat 2x%)
    bool findMatch(const vector<vector<int>>& matrix, const int target,
                    int begin, int end){
        int middle = (begin + end) / 2;
        int i = middle / n, j = middle % n;
        if(begin == end){ return matrix[i][j] == target; }
        
        if(matrix[i][j] < target) begin = middle + 1;
        else{
            end = middle;
        }
        return findMatch(matrix, target, begin, end);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix.size(), n = matrix[0].size();
        return findMatch(matrix, target, 0, m * n - 1);
    }
};