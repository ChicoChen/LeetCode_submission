class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // modified Dijkstra's algorithm
        vector<pair<int, int>>* edgeTable = new vector<pair<int, int>>[n];

        for(int i= 0; i< edges.size(); i++){
            edgeTable[edges[i][0]].emplace_back(edges[i][1], i);
            edgeTable[edges[i][1]].emplace_back(edges[i][0], i);
        }

        double* prob = new double[n]{};
        std::priority_queue<pair<double, int>,
                            vector<pair<double, int>>,
                            std::less<pair<double, int>>> pq;
        pq.emplace(1, start_node);
        while(!pq.empty()){
            pair<double, int> node = pq.top();
            pq.pop();
            if(node.second == end_node){ break; }
            if(node.first < prob[node.second]){ continue; }

            for(auto neighbor: edgeTable[node.second]){
                double new_prob = node.first * succProb[neighbor.second];
                if(new_prob <= prob[neighbor.first]){ continue; }
                //only update when new_prob > prob[neighbor.first]
                prob[neighbor.first] = new_prob;
                pq.emplace(new_prob, neighbor.first);
            }
        }

        // for(int i= 0; i< n; i++){
        //     delete[] edgeTable[i];
        // }
        // delete[] edgeTable;
        return prob[end_node];
    }
};