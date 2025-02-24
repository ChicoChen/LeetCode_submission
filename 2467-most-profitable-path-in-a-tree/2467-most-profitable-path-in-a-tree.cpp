class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        tree.resize(n, vector<int>());
        for(const auto &edge: edges){
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        bobFindPath(bob, visited);
        int middle_point = bob_path.size() / 2;
        if(bob_path.size() % 2 == 1){
            amount[bob_path[middle_point]] /= 2;
            middle_point++;
        }
        for(int i = middle_point; i < bob_path.size(); i++){
            amount[bob_path[i]] = 0;
        }

        return findMaxProfit(amount, 0);
    }

    bool bobFindPath(int bob, vector<bool> &visited){
        visited[bob] = true;
        if(bob == 0){
            bob_path.push_back(0);
            return true;
        }

        for(int neighbor: tree[bob]){
            if(visited[neighbor]) continue;
            else if(bobFindPath(neighbor, visited)){
                bob_path.push_back(bob);
                return true;
            }
        }
        return false;
    }

    int findMaxProfit(vector<int>& amount, int current){
        int profit = amount[current];
        int max_profit = INT_MIN;
        amount[current] = INT_MAX;
        for(int neighbor: tree[current]){
            if(amount[neighbor] == INT_MAX) continue;
            max_profit = max(profit + findMaxProfit(amount, neighbor), max_profit);
        }
        return (max_profit == INT_MIN)? profit: max_profit;
    }

private:
    vector<vector<int>> tree;
    vector<int> bob_path;
};