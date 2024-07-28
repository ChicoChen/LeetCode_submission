class Solution {
public:
    //LSD radix sort;
    vector<int> radixSort(const vector<int> &mapping,
                        const vector<int> nums,
                        int denominator){
        int count[10]{};
        vector<int> sorted(nums.size());
        for(int num: nums){
            if(num >= denominator){
                count[mapping[(num / denominator) % 10]] += 1;
            }
            else if(num == 0){ count[mapping[0]] += 1; }
            else{ count[0]++; }
        }

        int firstIdx = 0;
        for(int &cou: count){
            int temp = cou;
            cou = firstIdx;
            firstIdx += temp;
        }

        for(int i= 0; i< nums.size(); i++){
            int digit;
            if(nums[i] >= denominator){
                digit = mapping[(nums[i]/ denominator) % 10];
            }else if(nums[i] == 0){
                digit = mapping[0];
            }
            else{ digit = 0; }
            
            sorted[count[digit]] = nums[i];
            count[digit]++;
        }

        return sorted;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int max = *max_element(nums.begin(), nums.end());
        int denominator = 1;
        while(max / denominator > 0){
            nums = radixSort(mapping, nums, denominator);
            denominator *= 10;
        }
        return nums;
    }
};