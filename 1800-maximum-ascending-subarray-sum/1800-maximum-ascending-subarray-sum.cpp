class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int result = 0;
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= nums[i - 1]){
                result = max(result, sum);
                sum = nums[i];
            }
            else sum += nums[i];
        }
        result = max(result, sum);
        return result;
    }
};