class Solution {
public:
    //step 1: brute-force BFS, TLE
    //step 2: learn from solution, and think
    //        "wait, why DFS can while BFS can't, this isn't right"
    //step 3: modify solution to BFS version, AC
    //todo: step 4: study unionfind or floodfill
    int m, n;
    bool BFS(int i, int j, int mark,
            const vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if(grid1[i][j] != 1) return false;
        
        queue<pair<int, int>> que;
        que.emplace(i, j);

        bool isSubLand = true;
        while(!que.empty()){
            pair<int, int> head = que.front();
            que.pop();
            int head_i = head.first, head_j = head.second;
            //! crucial line for solving TLE
            //! without this, already explored island will need to explore again
            if(grid2[head_i][head_j] == mark) continue;

            if(grid1[head_i][head_j] != 1){
                isSubLand = false;
                continue;
            }

            //stand for visited
            grid2[head_i][head_j] = mark;

            if(head_i + 1 < m && grid2[head_i + 1][head_j] == 1){
                que.emplace(head_i + 1, head_j);
            }
            if(head_i - 1 >= 0 && grid2[head_i - 1][head_j] == 1){
                que.emplace(head_i - 1, head_j);
            }
            if(head_j + 1 < n && grid2[head_i][head_j + 1] == 1){
                que.emplace(head_i, head_j + 1);
            }
            if(head_j - 1 >= 0 && grid2[head_i][head_j - 1] == 1){
                que.emplace(head_i, head_j - 1);
            }
        }
        return isSubLand;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();   n = grid1[0].size();
        int answer= 0;
        int mark = 2;
        for(int i= 0; i< m; i++){
            for(int j = 0; j < n; j++){
                //not land in grid 2, must not be sub land
                if(grid2[i][j] != 1) continue;
                if(BFS(i, j, mark, grid1, grid2)){ answer++; }
            }
        }

        return answer;
    }
};