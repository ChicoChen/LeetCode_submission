class Solution {
public:
    //learn from solution
    int minSubarray(vector<int>& nums, int p) {
        int remainder = 0;
        for(int num : nums){
            remainder = (remainder + num) % p;
        }
        if(remainder == 0){ return 0;}

        unordered_map<int, int> hash({{0, -1}});
        
        int tail_r = 0;
        int result = nums.size();
        for(int i = 0; i< nums.size(); i++){
            tail_r = (tail_r + nums[i]) % p;
            int head_r = (p + tail_r - remainder) % p;
            if(hash.count(head_r)){
                result = min(result, i - hash[head_r]);
            }
            
            hash[tail_r] = i;
        }
        return result == nums.size()? -1: result;
    }
};
