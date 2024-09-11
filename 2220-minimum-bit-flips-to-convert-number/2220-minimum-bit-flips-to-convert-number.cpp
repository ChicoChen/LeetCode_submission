class Solution {
public:
    int minBitFlips(int start, int goal) {
        string start_bs = std::bitset<32>(start).to_string();
        string goal_bs = std::bitset<32>(goal).to_string();

        int count = 0;
        for(int i= 0; i< start_bs.size(); i++){
            if(start_bs[i] != goal_bs[i]) count++;
        }
        return count;
    }
};