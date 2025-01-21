class Solution {
public:
    //learn from Editorial
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long top_sum = 0, bottom_sum = 0;
        for(int i = 1; i < n; i++){
            top_sum += grid[0][i];
        }
        
        long long result = top_sum;
        for(int i = 1; i < n; i++){
            top_sum -= grid[0][i];
            bottom_sum += grid[1][i - 1];
            long long new_result = max(top_sum, bottom_sum);
            if(new_result < result) result = new_result;
        }

        return result;
    }
};