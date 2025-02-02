class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int min = 101;
        vector<int> starts;
        for(int i = 0; i < n; i++){
            if(nums[i] < min){
                min = nums[i];
                starts.clear();
                starts.push_back(i);
            }
            else if(nums[i] == min){
                starts.push_back(i);
            }
        }

        for(int start: starts){
            int previous = min;
            bool result = true;
            for(int i = 0; i < n; i++){
                int idx = (start + i) % n;
                if(nums[idx] < previous){
                    result = false;
                    break;
                }
                previous = nums[idx];
            }

            if(result) return true;
        }
        return false;
    }
};