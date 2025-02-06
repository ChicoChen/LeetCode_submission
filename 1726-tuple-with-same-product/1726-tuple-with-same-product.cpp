class Solution {
public:
    //I referred the hint
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> count;
        int result = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int product = nums[i] * nums[j];
                result += count[product] * 8;
                count[product]++;
            }
        }

        return result;
    }
};