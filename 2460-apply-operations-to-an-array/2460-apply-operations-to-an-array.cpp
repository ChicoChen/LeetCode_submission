class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n - 1; i++){
            if(nums[i] == nums[i + 1]){
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        for(int head = 0, tail = 0; tail < n; tail++){
            if(nums[tail] != 0){
                swap(nums[head], nums[tail]);
                head++;
            }
        }
        return nums;
    }
};