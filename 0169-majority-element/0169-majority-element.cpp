class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int start = 0;
        int count = 0;
        int answer = nums[0];
        for(int i= 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1]){
                if(i - start > count){
                    count =  i - start;
                    answer = nums[start]; 
                }
                start = i;
            }
        }
        if(nums.size() - start > count){
                    count =  nums.size() - start;
                    answer = nums.back(); 
                }
        return answer;
    }
};