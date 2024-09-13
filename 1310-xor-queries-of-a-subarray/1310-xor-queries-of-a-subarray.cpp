class Solution {
public:
    // take 1: DP approach -> MLE (actually a very close guess)
    // take 2: prefix sum
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int* table = new int[arr.size()];
        table[0] = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            table[i] = table[i - 1] ^ arr[i];
        }

        // hint: x ^ y ^ x = y;
        // hence [1~i] ^ [1~j] = [i~j]
        vector<int> answer;
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0], end = queries[i][1];
            if (!start)
                answer.push_back(table[end]);
            else
                answer.push_back(table[start - 1] ^ table[end]);
        }

        return answer;
    }
};