class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        // Editorial
        vector<vector<int>> neighbors(n);
        for (auto edge : edges) {
            int node1 = edge[0] - 1, node2 = edge[1] - 1;
            neighbors[node1].push_back(node2);
            neighbors[node2].push_back(node1);
        }

        unordered_map<int, int> component;
        vector<int> color(n, 0);
        int componentCount = 0;
        for (int i = 0; i < n; i++) {
            if (color[i])
                continue;

            color[i] = 1;
            component[i] = componentCount;
            queue<int> BFS;
            BFS.emplace(i);
            while (!BFS.empty()) {
                int current = BFS.front();
                BFS.pop();
                for (int neighbor : neighbors[current]) {
                    if (color[neighbor] == 0) {
                        color[neighbor] = 3 - color[current];
                        component[neighbor] = componentCount;
                        BFS.push(neighbor);
                    } else if (color[neighbor] == color[current])
                        return -1;
                }
            }
            componentCount++;
        }

        vector<int> groupInComponent(componentCount, 0);
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            queue<int> layers;
            visited[i] = true;
            layers.push(i);
            int distance = 0;
            while (!layers.empty()) {
                int numInLayer = layers.size();
                for (int node = 0; node < numInLayer; node++) {
                    int current = layers.front();
                    layers.pop();
                    for (int neighbor : neighbors[current]) {
                        if (visited[neighbor])
                            continue;
                        visited[neighbor] = true;
                        layers.push(neighbor);
                    }
                }
                distance++;
            }
            if (distance > groupInComponent[component[i]])
                groupInComponent[component[i]] = distance;
        }

        int numOfGroup = 0;
        for (int groupCount : groupInComponent) {
            numOfGroup += groupCount;
        }
        return numOfGroup;
    }
};