class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<int> row_count(m, n);
        vector<int> col_count(n, m);
        vector<pair<int, int>> pos(m * n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                pos[mat[i][j] - 1].first = i;
                pos[mat[i][j] - 1].second = j;
            }
        }

        for(int i = 0; i < m * n; i++){
            int idx = arr[i] - 1;
            int row = pos[idx].first;
            int col = pos[idx].second;
            if(--row_count[row] == 0 || --col_count[col] == 0){
                return i;
            }
        }
        return -1;
    }
};