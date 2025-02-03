class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int result = 0;
        int length = 1;
        int increasing = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]) {
                result = max(result, length);
                length = 1;
                increasing = 0;
            }
            else if(nums[i] > nums[i - 1]){
                if(increasing == 2){
                    result = max(result, length);
                    length = 2;
                }
                else length += 1;
                increasing = 1;
            }
            else{
                if(increasing == 1){
                    result = max(result, length);
                    length = 2;
                }
                else length += 1;
                increasing = 2;
            }
        }
        result = max(result, length);
        return result;
    }
};