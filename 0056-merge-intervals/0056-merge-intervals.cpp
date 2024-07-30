class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       std::sort(intervals.begin(), intervals.end());

        vector<vector<int>> answer;
        int start = intervals[0][0], end = intervals[0][1];
        for(int i= 1; i< intervals.size(); i++){
            if(intervals[i][0] <= end){
                end = (intervals[i][1] > end)? intervals[i][1]: end;
            }
            else{
                answer.emplace_back();
                answer.back().push_back(start);
                answer.back().push_back(end);

                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        answer.emplace_back();
        answer.back().push_back(start);
        answer.back().push_back(end);

        return answer;
    }
};