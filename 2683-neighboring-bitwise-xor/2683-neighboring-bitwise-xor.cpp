class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xor_sum = derived.front();
        for(int i = 1; i < derived.size(); i++){
            xor_sum = xor_sum ^ derived[i];
        }

        return xor_sum == 0;
    }
};