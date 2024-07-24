class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int count[201]{};
        for(int i= 0; i< nums.size(); i++){
            count[nums[i] + 100]++;
        }
        
        int minCount, value, swapTarget;
        for(int i= 0; i< nums.size() - 1; i++){
            swapTarget = i;
            value = nums[i];
            minCount = count[value + 100];
            for(int j = i + 1; j < nums.size(); j++){
                if(count[nums[j] + 100] < minCount){
                    value = nums[j];
                    minCount = count[value + 100];
                    swapTarget = j;
                }
                else if(count[nums[j] + 100] == minCount
                        && nums[j] > value){
                    value = nums[j];
                    minCount = count[value + 100];
                    swapTarget = j;
                }
            }
            int temp = nums[i];
            nums[i] = nums[swapTarget];
            nums[swapTarget] = temp;
        }
        return nums;
    }
};