class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> count;
        count[nums[0]]++;

        int result = 0;
        for(int j = 1; j < nums.size(); j++){
            int minus = nums[j] - j;
            result += (j - count[minus]);
            count[minus]++;
        }

        return result;
    }
};