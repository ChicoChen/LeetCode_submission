class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n, 0);
        vector<int> ballColor(limit + 1, 0);
        unordered_map<int, int> colorCount;
        for(int i = 0; i < n; i++){
            result[i] = (i == 0)? 0: result[i - 1];
            int label = queries[i][0];
            int color  = queries[i][1];
            
            if(colorCount[color] == 0){
                result[i]++;
            }
            colorCount[color]++;

            int original = ballColor[label];
            ballColor[label] = color;
            if(original != 0){
                colorCount[original]--;
                if(colorCount[original] == 0){
                    result[i]--;
                    colorCount.erase(original);
                }
            }
        }
        return result;
    }
};