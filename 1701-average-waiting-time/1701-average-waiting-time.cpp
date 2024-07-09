class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long whenFinish = 0;
        long long totalWaitingTime = 0;
        for(auto &iter: customers){
            if(iter[0] < whenFinish){
                whenFinish += iter[1];
            }
            else{ whenFinish = iter[0] + iter[1]; }
            totalWaitingTime += whenFinish - iter[0];
        }

        return  double(totalWaitingTime)/customers.size();
    }
};