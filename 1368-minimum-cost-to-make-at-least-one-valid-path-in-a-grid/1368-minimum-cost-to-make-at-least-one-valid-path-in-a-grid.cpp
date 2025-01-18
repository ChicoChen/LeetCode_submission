//learn from hint
class Solution {
public:
    struct node{
        int i, j;
        bool visited = false;
        vector<int> edges; // right, left, down, up

        node(int i, int j, int direction, int m, int n):
            i(i), j(j), edges(4, 1){
            edges[direction - 1] = 0;
            if(j == n - 1) edges[0] = -1;
            else if(j == 0) edges[1] = -1;

            if(i == m - 1) edges[2] = -1;
            else if(i == 0) edges[3] = -1;
        }
        
        int operator[](int direction){
            return edges[direction];
        }

        void get_neighbor(int &i, int &j, int direction){
            // right, left, down, up
            int offset = (direction % 2)? -1: 1;
            if(direction < 2) j += offset;
            else i +=  offset;
        }
    };

    struct path{
        int cost;
        node* node;
        path(int cost, struct node* node): cost(cost), node(node){}
    };

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        //initialize nodes
        vector<vector<node>> nodes(m);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                nodes[i].emplace_back(i, j, grid[i][j], m, n);
            }
        }

        deque<path> BFS;
        
        int result;
        BFS.emplace_back(0, &nodes[0][0]);
        while(!BFS.empty()){
            path current = BFS.front();
            BFS.pop_front();
            node &pos = *current.node;
            if(pos.visited) continue;

            pos.visited = true;
            if(pos.i == m - 1 && pos.j == n - 1){
                result = current.cost;
                break;
            }

            for(int k = 0; k < 4; k++){
                if(pos.edges[k] < 0) continue;
                
                int i = pos.i, j = pos.j;
                pos.get_neighbor(i, j, k);
                if(nodes[i][j].visited) continue;

                if(pos.edges[k] == 0) BFS.emplace_front(current.cost, &nodes[i][j]);
                else BFS.emplace_back(current.cost + pos.edges[k], &nodes[i][j]);
            }

        }
        return result;
    }
};