class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        std::priority_queue<int, vector<int>, std::less<int>> pq;
        for(int num: nums){ pq.push(num); }

        long long answer = 0;
        for(int i= 0; i< k; i++){
            int max = pq.top();
            answer += max;
            pq.pop();
            max = (max % 3)?max / 3 + 1: max / 3;
            pq.push(max);
        }

        return answer;
    }
};