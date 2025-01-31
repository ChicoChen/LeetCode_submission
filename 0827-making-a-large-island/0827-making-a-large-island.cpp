class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int result = 0;

        vector<int> landSize;
        int landID = 0;

        vector<vector<int>> land(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;
                else if(land[i][j] != -1) continue;

                int area = 0;
                queue<pair<int, int>> BFS;
                BFS.emplace(i, j);
                land[i][j] = landID;
                while(!BFS.empty()){
                    auto current = BFS.front();
                    BFS.pop();
                    area++;
                    for(const auto &dir: directions){
                        int x = current.first + dir.first;
                        int y = current.second + dir.second;
                        if((x + 1) % (n + 1) == 0 || (y + 1) % (n + 1) == 0) continue;
                        else if(grid[x][y] != 1) continue;
                        else if(land[x][y] != -1) continue;

                        BFS.emplace(x, y);
                        land[x][y] = landID;
                    }
                }
                if (area > result) result = area;
                landSize.push_back(area);
                landID++;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0) continue;
        
                unordered_set<int> neighbor;
                for(const auto & dir: directions){
                    int x = i + dir.first;
                    int y = j + dir.second;
                    if((x + 1) % (n + 1) == 0 || (y + 1) % (n + 1) == 0) continue;

                    neighbor.insert(land[x][y]);
                }
                
                int total = 1;
                for(auto ID: neighbor){
                    if(ID == -1) continue;
                    total += landSize[ID]; 
                }

                if (total> result) result = total;
            }
        }
        return result;
    }
};