class Solution {
    class Cell{
     public:
        int i;
        int j;
        int height;
        Cell(int i, int j, int height): i(i), j(j), height(height){}
        bool operator>(const Cell &other) const { return height > other.height; }
    };

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> heights(m, vector<int>(n, -1));
        priority_queue<Cell, vector<Cell>, std::greater<Cell>> BFS;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j] == 0) continue;
                BFS.emplace(i, j, 0);
                heights[i][j] = 0;
            }
        }

        while(!BFS.empty()){
            Cell cell = BFS.top();
            BFS.pop();

            for(const auto &direction: directions){
                int i_offset = direction.first, j_offset = direction.second;
                int target_i = cell.i + i_offset, target_j = cell.j + j_offset;
                if((target_i + 1) % (m + 1) == 0 || (target_j + 1) % (n + 1) == 0) continue;
                else if(heights[target_i][target_j] != -1) continue;

                heights[target_i][target_j] = cell.height + 1;
                BFS.emplace(target_i, target_j, cell.height + 1);
            }

        }
        return heights;
    }
};