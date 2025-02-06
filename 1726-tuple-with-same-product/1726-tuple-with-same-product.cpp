class Solution {
public:
    //I referred the hint
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        //std::sort(nums.begin(), nums.end());
        unordered_map<int, int> count;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                count[nums[i] * nums[j]]++;
            }
        }

        int result = 0;
        for(auto cnt: count){
            result += cnt.second * (cnt.second - 1) * 4;
        }

        return result;
    }
};