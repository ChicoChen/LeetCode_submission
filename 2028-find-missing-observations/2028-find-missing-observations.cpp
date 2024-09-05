class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int m_sum = 0;
        for(int i= 0; i< m; i++) m_sum += rolls[i];
        int n_sum = mean * (n + m) - m_sum;

        vector<int> answer;
        if(n_sum < n || n_sum > n * 6) return answer;

        for(int i= 1; i<= n; i++){
            //greedyly: push_back maximun number answer[i] can have
            answer.push_back(min(6, n_sum - (n - i)));
            n_sum -= answer.back();
        }

        return answer;
        
    }
};