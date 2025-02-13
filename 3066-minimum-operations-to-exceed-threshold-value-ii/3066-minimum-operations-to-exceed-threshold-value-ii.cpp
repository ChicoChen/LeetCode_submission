class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        std::priority_queue<long long, vector<long long>, std::greater<long long>> pq(nums.begin(), nums.end());

        int counter = 0;
        while(nums.size() >= 2){
            long long min = pq.top();
            if(min >= k) break;

            min *= 2;
            pq.pop();
            min += pq.top();
            pq.pop();
            pq.push(min);
            counter++;
        }
        return counter;
    }
};