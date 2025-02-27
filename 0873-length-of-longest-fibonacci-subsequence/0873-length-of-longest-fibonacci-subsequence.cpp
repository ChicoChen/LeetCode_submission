class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int result = 0;
        unordered_map<int, int> val2idx;
        for(int i = 0 ; i < n; i++){
            val2idx[arr[i]] = i;
        }

        vector<vector<int>> len(n, vector<int>(n, 0));
        for(int i = 0; i < n - 1 ; i++){
            for(int j = i + 1; j < n; j++){
                auto iter = val2idx.find(arr[j] - arr[i]);
                if(iter != val2idx.end() && iter->second < i){
                    len[i][j] = len[iter->second][i] + 1;
                }
                else{
                    len[i][j] = 2;
                }
                result = max(result, len[i][j]);
            }
        }

        return result;
    }
};