class Solution {
public:
    int minimumLength(string s) {
        int count[26]{};
        for(char c: s){ count[c - 'a']++; }

        int minSize = 0;
        for(int i= 0; i < 26; i++){
            if(count[i] >= 3){
                count[i] = (count[i] % 2)? 1: 2;
            }

            minSize += count[i];
        }

        return minSize;
    }
};