class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size() != s2.size()) return false;

        char target = ' ', current = ' ';
        int difference = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                difference++;
                if(difference == 1){
                    target = s1[i];
                    current = s2[i];
                }
                else if(difference == 2){
                    if(s1[i] == current && s2[i] == target) { continue; }
                    else return false;
                }
                if(difference >= 3){ return false; }
            }
        }
        return difference % 2 == 0;
    }
};