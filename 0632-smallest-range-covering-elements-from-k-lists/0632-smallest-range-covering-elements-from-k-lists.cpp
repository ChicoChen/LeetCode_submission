class Solution {
public:
    //take one: come up with "Optimal Brute Force" myself
    //take two: learn from editorial: heap approach
    void compareNums(vector<vector<int>>& nums, int *index,
                    int &min, int &row_idx, int &max)
    {
        row_idx = 0;
        min = nums[0][index[0]];
        max = nums[0][index[0]];
        
        for(int i= 1; i< nums.size(); i++){
            if(nums[i][index[i]] < min){
                row_idx = i;
                min = nums[i][index[i]];
            }
            else if(nums[i][index[i]] > max){
                max = nums[i][index[i]];
            }
        }
    }

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int range = INT_MAX;
        int start = INT_MAX;
        int max = INT_MIN;
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>, greater<>> pq;
        for(int i= 0; i < nums.size(); i++){
            pq.emplace(nums[i][0], i);
            max = std::max(max, nums[i][0]);
        }

        int *index = new int[nums.size()]{};
        while(true){
            pair<int, int> min_element = pq.top();
            pq.pop();
            if(max - min_element.first < range ||
               (max - min_element.first == range && min_element.first < start))
            {
                range = max - min_element.first;
                start = min_element.first;
            }

            int row_idx = min_element.second;
            index[row_idx]++;
            if(index[row_idx] >= nums[row_idx].size()){
                break;
            }
            pq.emplace(nums[row_idx][index[row_idx]], row_idx);
            max = std::max(nums[row_idx][index[row_idx]], max);
        }

        vector<int> answer;
        answer.push_back(start);
        answer.push_back(start + range);
        return answer;
    }
};