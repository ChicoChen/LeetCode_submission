class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int* count = new int[int(pow(10, 5)) + 1]{};
        int min = *min_element(nums.begin(), nums.end());
        min = std::min(min, 0);
        for(int &ele:nums){
            ele -= min;
            count[ele] += 1;
        }

        int startIdx = 0;
        for(int i= 0; i< int(pow(10, 5)) + 1; i++){
            int temp = count[i];
            count[i] = startIdx;
            startIdx += temp;
        }

        vector<int> sortedNums(nums.size());
        for(int ele:nums){
            sortedNums[count[ele]] = ele + min;
            count[ele] += 1;
        }
        delete[] count;
        return sortedNums;
    }
};