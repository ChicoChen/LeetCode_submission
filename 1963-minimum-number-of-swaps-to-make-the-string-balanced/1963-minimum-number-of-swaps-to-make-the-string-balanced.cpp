class Solution {
public:
    int minSwaps(string s) {
        std::stack<char> brackets;
        for(char c: s){
            if(brackets.size() != 0 && c == ']' && brackets.top() == '['){
                brackets.pop();
            }
            else { brackets.push(c); }
        }

        //learn form editorial: each swap can resolve maximum 2 pairs of unmatched brackets
        int unmatchedPairs = brackets.size() / 2;
        return (unmatchedPairs + 1) / 2;
    }
};