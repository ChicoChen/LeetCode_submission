class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> root(n, -1);
        for(auto edge: edges){
            int nodeA = edge[0] - 1 , nodeB = edge[1] - 1;
            while(root[nodeA] != -1){ nodeA = root[nodeA]; }
            while(root[nodeB] != -1){ nodeB = root[nodeB]; }
            if(nodeA == nodeB) return edge;
            else if(nodeA < nodeB){ root[nodeB] = nodeA; }
            else{ root[nodeA] = nodeB; }
        }
        return vector<int>();
    }
};