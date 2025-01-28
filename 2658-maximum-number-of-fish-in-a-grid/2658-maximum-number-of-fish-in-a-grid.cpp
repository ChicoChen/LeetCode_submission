class Solution {
public:
    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int searchCurrentArea(queue<pair<int, int>> &BFS, vector<vector<int>> &grid){
        int m = grid.size(), n = grid[0].size();
        int areaSum = 0;
        while(!BFS.empty()){
            auto block = BFS.front();
            BFS.pop();
            if(grid[block.first][block.second] == 0) continue;
            
            areaSum += grid[block.first][block.second];
            grid[block.first][block.second] = 0;
            for(auto dir: directions){
                int i = block.first + dir.first;
                int j = block.second + dir.second;
                if((i + 1) % (m + 1) == 0 || (j + 1) % (n + 1) == 0) continue;
                else if(grid[i][j] == 0) continue;
                else BFS.emplace(i, j);
            }
        }
        return areaSum;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> BFS;

        int result = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;

                BFS.emplace(i, j);
                int newResult = searchCurrentArea(BFS, grid);
                result = (newResult > result)? newResult: result;
            }
        }
        return result;
    }
};