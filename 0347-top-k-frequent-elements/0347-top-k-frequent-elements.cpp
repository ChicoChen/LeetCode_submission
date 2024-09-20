class Solution {
public:
    // take 1: merge sort using count -> undone
    // take 2: count + priority_queue
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (auto num : nums) {
            count[num] += 1;
        }

        priority_queue<pair<int, int>> pq;
        for(auto iter = count.begin(); iter != count.end(); iter++){
            pq.emplace(iter->second, iter->first); //pair compare 1st element first.
        }
        
        vector<int> answer;
        for(int i= 0; i< k; i++){
            answer.push_back(pq.top().second);
            pq.pop();
        }
        return answer;
    }
};