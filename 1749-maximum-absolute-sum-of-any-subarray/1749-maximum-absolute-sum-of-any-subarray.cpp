class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        // list<int> sub_sums;
        // sub_sums.push_back(nums[0]);

        int pos_sum = 0, neg_sum = 0;
        if(nums[0] > 0) pos_sum += nums[0];
        else neg_sum += nums[0];

        for(int i = 1; i < n; i++){
            if(nums[i] > 0){
                result = max(result, -neg_sum);
                if(nums[i] + neg_sum >= 0) neg_sum = 0;
                else neg_sum += nums[i];
                pos_sum += nums[i];
            }
            else{
                result = max(result, pos_sum);
                if(-nums[i] >= pos_sum) pos_sum = 0;
                else pos_sum += nums[i];
                neg_sum += nums[i];
            }
            // bool new_candidate = false;
            // for(auto iter = sub_sums.begin(); iter != sub_sums.end();){
            //     if(nums[i] > 0 == *iter > 0){
            //         *iter += nums[i];
            //         iter++;
            //         continue;
            //     }
            
            //     result = max(result, abs(*iter));
            //     new_candidate = true;
            //     if(abs(nums[i]) >= abs(*iter)) iter = sub_sums.erase(iter);
            //     else {
            //         *iter += nums[i];
            //         iter++;
            //     }
            // }

            // if(new_candidate) sub_sums.push_back(nums[i]);
        }

        // for(auto sum: sub_sums){
        //     result = max(sum, abs(result));
        // }

        result = max(result, max(pos_sum, -neg_sum));
        return result;
    }
};