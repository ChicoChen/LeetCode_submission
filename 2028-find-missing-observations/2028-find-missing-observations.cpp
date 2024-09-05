class Solution {
public:
          
//take 1-greedyalgorithm: push_back maximun number answer[i] can have
//take 2: learn from editorial
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int m_sum = 0;
        for(int i= 0; i< m; i++) m_sum += rolls[i];
        int n_sum = mean * (n + m) - m_sum;
        
        //? instead of return vector<int>(), return {} is faster.
        if(n_sum < n || n_sum > n * 6) return {};

        int n_mean = n_sum / n;
        int n_remain = n_sum % n;
        vector<int> answer(n, n_mean);
        for(int i = 0; i< n_remain; i++){
            answer[i]++;
        }

        return answer;
        
    }
};