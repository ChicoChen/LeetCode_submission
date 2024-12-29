class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> kSum(n, 0);
        kSum[n - 1] = nums[n - 1];
        // instead of calculate postfixSum, directly calculate sum of k elements starting at i 
        for(int i = n - 2; i >= 0; i--){
            kSum[i] = kSum[i + 1] + nums[i];
            if(i < n - k) kSum[i] -= nums[i + k]; 
        }

        // max sum of subarrays within scope [i: n)
        // length is set to n + 1 because of edge-case k = 1 
        vector<vector<int>> maxSum(3, vector<int>(n + 1, -1));
        // the starting position of the first included subarray
        vector<vector<int>> startIdx(3, vector<int>(n, -1));
        for(int i = 0; i < 3; i++){
            for(int ele = n - k * (i + 1); ele >= 0; ele--){
                int currentSum = (i == 0)?
                                 kSum[ele]:
                                 kSum[ele] + maxSum[i - 1][ele + k];
                // use >= to track the result with least lexical order
                if(currentSum >= maxSum[i][ele + 1]){
                    maxSum[i][ele] = currentSum;
                    startIdx[i][ele] = ele;
                }
                else{
                    maxSum[i][ele] = maxSum[i][ele + 1];
                    startIdx[i][ele] = startIdx[i][ele + 1];
                }
            }
        }

        // reconstruct the maximum sum subarrays
        vector<int> result(3, 0);
        int nextStart = 0;
        for(int i= 0; i < 3; i++){
            result[i] = startIdx[2-i][nextStart];
            nextStart = result[i] + k;
        }
        return result;
    }
};