class Solution {
public:
    //refer to hint: sliding window
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        vector<int> alphabet(26, 0);
        for(char c: s1){
            alphabet[c - 'a']++;
        }

        int head = 0,   tail = 0;
        for( ; tail < s2.size(); tail++){
            char c = s2[tail];
            
            // pos[c - 'a'].push(tail);
            alphabet[c - 'a']--;
            while(alphabet[c - 'a'] < 0){
                alphabet[s2[head] - 'a']++;
                head++;
            }
            if(tail - head == n - 1){ return true;}
        }

        return false;
    }
};