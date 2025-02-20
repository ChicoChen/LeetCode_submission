class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> used(nums.begin(), nums.end());
        string result(n, '_');
        backtracking(result, 0, used);
        return result;
    }
    
    bool backtracking(string &result, int idx, const unordered_set<string>& used){
        if(idx == result.size()){
            return used.count(result) == 0; 
        }

        for(char bit = '0'; bit < '2'; bit++){
            result[idx] = bit;
            if(backtracking(result, idx + 1, used)) return true;
        }
        return false;
    }
};