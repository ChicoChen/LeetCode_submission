class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<int>> hashTable;
        string sorted;
        for(int i= 0; i< strs.size(); i++){
            sorted = strs[i];
            std::sort(sorted.begin(), sorted.end());
            hashTable[sorted].push_back(i);
        }

        vector<vector<string>> answer;
        for(auto iter: hashTable){
            answer.emplace_back();
            for(int idx: iter.second){
                answer.back().push_back(strs[idx]);
            }
        }
        return answer;
    }
};