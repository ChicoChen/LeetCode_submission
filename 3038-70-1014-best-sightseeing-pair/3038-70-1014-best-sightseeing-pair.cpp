class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int len = values.size();
        int maxParner = 0;
        int maxScore = 0;
        for(int i = 1; i < len; i++){
            maxParner = (maxParner > values[i - 1])?
                            maxParner - 1:
                            values[i - 1] - 1; 
            int score = values[i] + maxParner;
            maxScore = (score > maxScore)? score : maxScore;
        }

        return maxScore;
    }
};