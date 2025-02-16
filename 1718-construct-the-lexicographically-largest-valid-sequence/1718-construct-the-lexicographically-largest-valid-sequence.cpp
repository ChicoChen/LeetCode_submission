class Solution {
public:
    bool backtracking(vector<int> &result, vector<bool> used, int idx){
        if(idx == result.size()) return true;
        else if(result[idx] != 0) return backtracking(result, used, idx + 1);
        
        int n = used.size() - 1;
        for(int i = n; i >= 2; i--){
            if(used[i] || idx + i >= result.size()) continue;
            else if(result[idx + i] != 0) continue;
            
            used[i] = true;
            result[idx] = i;
            result[idx + i] = i;

            if(backtracking(result, used, idx + 1)) return true;
            else{
                used[i] = false;
                result[idx] = 0;
                result[idx + i] = 0;
            }
        }

        if(!used[1]){
            result[idx] = 1;
            used[1] = true;
            if(backtracking(result, used, idx + 1)) return true;
            else{
                result[idx] = 0;
                used[1] = false;
            }
        }
        
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        backtracking(result, used, 0);

        return result;
    }
};