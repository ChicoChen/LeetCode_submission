class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //bucket sort or counting sort
        //nah, mybe no sorting needed?
        //maybe just a for-loop?

        //48ms, Beats 44.34%
        /*
        vector<int> count(1e5, 0);
        vector<int> answer;
        for(int num: nums){
            if(count[num - 1]) answer.push_back(num);
            count[num - 1]++;
        }
        return answer;
        */

        //provided solution
        vector<int> answer;
        for(int i= 0; i < nums.size(); i++){
            if(nums[abs(nums[i]) - 1] < 0){ answer.push_back(abs(nums[i])); }
            else{ nums[abs(nums[i]) - 1] *= -1; }
        }
        return answer;
    }
};