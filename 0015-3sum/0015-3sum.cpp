class Solution {
public:
    vector<vector<int>> answer;
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            int lPtr = i + 1, rPtr = nums.size() - 1;
            if(i > 0 && nums[i - 1] == nums[i]){ continue; }
            computeSum(i, lPtr, rPtr, nums);
        }
        return answer;
    }

    void computeSum(int i, int lPtr, int rPtr, vector<int> &nums){
        while(lPtr < rPtr){
            if(nums[i] + nums[lPtr] + nums[rPtr] == 0){
                answer.push_back(vector<int>());
                answer.back().push_back(nums[i]);
                answer.back().push_back(nums[lPtr]);
                answer.back().push_back(nums[rPtr]);

                while(lPtr < nums.size() - 1){
                    lPtr++;
                    if(nums[lPtr] != nums[lPtr - 1]){ break; }
                }
                while(rPtr > 0){
                    rPtr--;
                    if(nums[rPtr + 1] != nums[rPtr]){ break; }
                }
            }

            else if(nums[i] + nums[lPtr] + nums[rPtr] < 0){
                lPtr += 1;
            }
            else{ rPtr -= 1; }
        }
    }
};