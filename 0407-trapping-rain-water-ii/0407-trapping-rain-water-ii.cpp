//learn from Editorial
struct boundary{
    int i, j;
    int height;
    boundary(int i, int j, int height): i(i), j(j), height(height) {}

    bool operator>(const boundary &other) const {
        return height > other.height;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int m = heightMap.size();
        int n = heightMap[0].size();
        if(m <= 2 || n <= 2) return 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int result = 0;
        priority_queue<boundary, vector<boundary>, std::greater<boundary>> boundaries;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i % (m - 1) != 0 && j % (n - 1) != 0) continue;
                boundaries.emplace(i,j, heightMap[i][j]);
                visited[i][j] = true;
            }
        }

        while(!boundaries.empty()){
            boundary current = boundaries.top();
            boundaries.pop();
            int x = current.i, y = current.j;
            for(auto dir : directions){
                int i = dir.first, j = dir.second;
                if((x + i + 1) % (m + 1) == 0 || (y + j + 1) % (n + 1) == 0)
                    continue;
                else if(visited[x + i][y + j]) continue;

                int capacity = (current.height - heightMap[x + i][y + j]);
                if(capacity > 0){
                    boundaries.emplace(x + i, y + j, current.height);
                    result += capacity;
                }
                else{ boundaries.emplace(x + i, y + j, heightMap[x + i][y + j]); }
                visited[x + i][y + j] = true;
            }
        }
        return result;
    }
};