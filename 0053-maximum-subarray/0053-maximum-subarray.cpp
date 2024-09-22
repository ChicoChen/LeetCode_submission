class Solution {
public:
    //take 1: basic DP approach
    //TODO: speed up
    int maxSubArray(vector<int>& nums) {
        int *maxSumFrom = new int[nums.size()];
        maxSumFrom[nums.size() - 1] = nums[nums.size() - 1];
        for(int i= nums.size() - 2; i >= 0; i--){
            // maxSumFrom[i] = max(nums[i], nums[i] + maxSumFrom[i + 1]); 
            maxSumFrom[i] = nums[i];
            if(maxSumFrom[i + 1] > 0){ maxSumFrom[i] += maxSumFrom[i + 1]; }
        }

        int* max_ptr = max_element(maxSumFrom, maxSumFrom + nums.size());
        return *max_ptr;
    }
};