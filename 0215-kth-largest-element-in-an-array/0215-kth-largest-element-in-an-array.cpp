class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //1st try-selection sort: TLE
        //2nd try-counting sort: pass, but must exist better way
        int numRange = (int)pow(10, 4) * 2 + 1;
        int* count = new int[numRange]{};

        int minValue = *min_element(nums.begin(), nums.end());
        minValue = min(minValue, 0);
        for(int i= 0; i< nums.size(); i++){
            count[nums[i] - minValue]++;
        }

        int startIdx = 0;
        for(int i= 0; i< numRange; i++){
            int temp = startIdx;
            startIdx += count[i];
            count[i] = temp;
        }

        int answer = numRange - 1;
        for(; answer >= 0; answer--){
            if(count[answer] <= nums.size() - k){ break; }
        }
        
        return answer + minValue;
    }
};