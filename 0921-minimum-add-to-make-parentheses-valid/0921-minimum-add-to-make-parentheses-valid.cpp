class Solution {
public:
    int minAddToMakeValid(string s) {
        std::stack<char> parentheses;
        int unmatched = 0;
        for(char c: s){
            if(c == '('){ parentheses.push(c); }
            else{
                if(parentheses.size() == 0){
                    unmatched++;
                }
                else{ parentheses.pop(); }
            }
        }

        return unmatched + parentheses.size();
    }
};