class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for(int num: nums){ sum += num; }
        
        long long split = 0;
        int totalValid = 0;
        for(int i = 0; i < n - 1; i++){
            split += nums[i];
            sum -= nums[i];
            if(split >= sum) totalValid++;
        }

        return totalValid;
    }
};