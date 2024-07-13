//start after studied the solution
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        long long numBuckets = 20;
        int max = *std::max_element(nums.begin(), nums.end());
        std::vector<std::vector<int>> buckets(numBuckets, std::vector<int>());
        for(int i= 0; i< nums.size(); i++){
            if(nums[i] == max){
                buckets[numBuckets - 1].push_back(nums[i]);
                continue;
            }
            buckets[numBuckets * nums[i] / max].push_back(nums[i]);
        }
        nums.clear();

        for(int i= 0; i< numBuckets; i++){
            std::sort(buckets[i].begin(), buckets[i].end());
            nums.insert(nums.end(), buckets[i].begin(), buckets[i].end());
        }

        int answer = 0;
        for(int i= 0; i< nums.size() - 1; i++){
            answer = (nums[i + 1] - nums[i] > answer)? nums[i + 1] - nums[i]: answer;
        }

        return answer;
    }
};