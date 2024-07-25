class Solution {
public:
    void sortColors(vector<int>& nums) {
        //inplace selection sort
        int swapTarget, minValue;
        for(int i= 0; i< nums.size() - 1; i++){
            swapTarget = i;
            minValue = nums[i];
            for(int j = i + 1; j< nums.size(); j++){
                if(nums[j] < minValue){
                    swapTarget = j;
                    minValue = nums[j];
                }
            }
            
            int temp = nums[i];
            nums[i] = nums[swapTarget];
            nums[swapTarget] = temp;
        }
    }
};