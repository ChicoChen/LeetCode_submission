class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<int> value(1001, 0);
        for(auto tup: nums1){
            value[tup[0]] += tup[1];
        }

        for(auto tup: nums2){
            value[tup[0]] += tup[1];
        }
        vector<vector<int>> result;
        for(int i = 1; i < value.size(); i++){
            if(value[i] == 0) continue;
            result.push_back(std::vector<int>{i, value[i]});
        }
        return result;
    }
};