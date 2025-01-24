class Solution {
public:
    bool DFS(int idx, vector<vector<int>>& graph,
            unordered_set<int> &safeNodes, vector<bool> &visited)
    {
        visited[idx] = true;
        for(int neighbor: graph[idx]){
           if(visited[neighbor]){
                if(safeNodes.contains(neighbor)) continue;
                else return false;
            }
            else if(!DFS(neighbor, graph, safeNodes, visited)) return false;
        }

        safeNodes.insert(idx);
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        unordered_set<int> safeNodes;
        for(int i = 0; i < n; i++){
            if(graph[i].empty()){
                visited[i]= true;
                safeNodes.insert(i);
            }
        }

        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            DFS(i, graph, safeNodes, visited);
        }

        vector<int> result(safeNodes.begin(), safeNodes.end());
        std::sort(result.begin(), result.end());
        return result;
    }
};