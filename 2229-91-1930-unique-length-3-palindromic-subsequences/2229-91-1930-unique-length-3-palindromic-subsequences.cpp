class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for(int i = 0; i < s.size(); i++){
            int c = s[i] - 'a';
            if(first[c] == -1) first[c] = i;
            last[c] = i;
        }

        int answer = 0;
        for(int c = 0; c < 26; c++){
            if(first[c] == last[c]) continue;
            
            unordered_set<char> middleChar;
            for(int i = first[c] + 1; i < last[c]; i++){
                middleChar.insert(s[i]);
            }
            answer += middleChar.size();
        }

        return answer;
    }
};