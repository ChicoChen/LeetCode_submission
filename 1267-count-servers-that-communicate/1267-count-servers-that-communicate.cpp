class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;

                rowCount[i]++;
                colCount[j]++;
            }
        }

        int result = 0;
        for(int i = 0; i < m; i++){
            if(rowCount[i] >= 2){
                result += rowCount[i];
                continue;
            }

            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;
                
                if(colCount[j] >= 2) result++;
            }
        }

        return result;
    }
};