class Solution {
public:
    //exercise: BIT
    //write element and extract sum both in O(logN) time
    void initBIT(vector<int> &BIT){
        for(int i= 1; i < BIT.size(); i++){
            int parent = i + (i & -i);
            if(parent < BIT.size())BIT[parent] += BIT[i];
        }
    }

    void updateBIT(vector<int> &BIT, int index, int value){
        int parent = index;
        while(parent < BIT.size()){
            BIT[parent] += value;
            parent += (parent & -parent);
        }
    }

    int querySum(const vector<int> &BIT, int index){
        int sum = 0;
        while(index > 0){
            sum += BIT[index];
            index -= (index & -index);
        }
        return sum;
    }

    vector<int> countSmaller(vector<int>& nums) {
        int max = *std::max_element(nums.begin(), nums.end());
        int min = *std::min_element(nums.begin(), nums.end());
        int offset = 1 - min;

        vector<int> count(max - min + 2, 0); //leave count[0] empty
        for(int num: nums){
            count[num + offset] += 1;
        }
        initBIT(count);

        vector<int> result;
        for(int num: nums){
            result.push_back(querySum(count, num + offset - 1));
            updateBIT(count, num + offset, -1);
        }
        return result;
    }
};