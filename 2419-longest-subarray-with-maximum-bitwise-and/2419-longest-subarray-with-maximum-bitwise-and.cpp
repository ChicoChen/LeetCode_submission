class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //hint: braintester -> wait, doesn't bitwise AND only decrease the value?
        //! find the longest subarray which only conntail maximum
        int max = *std::max_element(nums.begin(), nums.end());
        int currLength = 0, maxLength = 0;
        for(int i= 0; i< nums.size(); i++){
            if(nums[i] == max){currLength++;}
            else {
                maxLength = (currLength > maxLength)? currLength: maxLength;
                currLength = 0;
            }
        }
        maxLength = (currLength > maxLength)? currLength: maxLength;

        return maxLength;
    }
};