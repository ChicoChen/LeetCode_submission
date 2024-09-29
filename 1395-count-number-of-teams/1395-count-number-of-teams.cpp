class Solution {
public:
    //learn from Editorial: Binary Indexed Tree approach
    //Todo: study DP method Editorial later
    void update(vector<int> &BIT, int idx, int value){
        while(idx < BIT.size()){
            BIT[idx] += value;
            idx += (idx & -idx);
        }
    }

    int prefixSum(const vector<int> &BIT, int idx){
        int sum = 0;
        while(idx > 0){
            sum += BIT[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
    
    int numTeams(vector<int>& arr) {
       int maxRating = *max_element(arr.begin(), arr.end());
        vector<int> leftBIT(maxRating + 1, 0);
        vector<int> rightBIT(maxRating + 1, 0);
        for(int i= 0; i< arr.size(); i++){
            update(rightBIT, arr[i], 1); //calculate occurence
        }

        int teamsCount = 0;
        for(int i= 0; i< arr.size(); i++){
            update(rightBIT, arr[i], -1);//remove current rating

            int smallRating_left = prefixSum(leftBIT, arr[i] - 1);
            int largeRating_left = i - smallRating_left; //leftBIT's size = i 

            int smallRating_right = prefixSum(rightBIT, arr[i] - 1);
            int largeRating_right = (arr.size() - 1 - i) - smallRating_right; //rightBIT's size = n - 1 - i 
        
            teamsCount += smallRating_right * largeRating_left;
            teamsCount += smallRating_left * largeRating_right;

            update(leftBIT, arr[i], 1);
        }

        return teamsCount;
    }
};