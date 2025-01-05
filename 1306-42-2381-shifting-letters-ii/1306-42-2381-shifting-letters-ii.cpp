class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        std::vector<int> totalShift(n, 0);
        for(auto step: shifts){
            int direction = (step[2])? 1: -1;
            totalShift[step[0]] += direction;
            if(step[1] + 1 < n) totalShift[step[1] + 1] -= direction;
        }

        for(int i = 0; i < n; i++){
            if(i) totalShift[i] += totalShift[i-1];
            int offset = (s[i] - 'a' + totalShift[i]) % 26;
            if(offset < 0) offset += 26;
            s[i] = 'a' + offset;
        }
        return s;
    }
};