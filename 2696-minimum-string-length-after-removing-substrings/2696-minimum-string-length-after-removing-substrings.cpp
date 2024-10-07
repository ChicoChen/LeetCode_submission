class Solution {
public:
    int minLength(string s) {
        std::stack<char> str;
        for(char c: s){
            if(str.size() < 1){
                str.push(c);
                continue;
            }

            if(c == 'B' && str.top() == 'A'){
                str.pop();
            }
            else if(c == 'D' && str.top() == 'C'){
                str.pop();
            }
            else{
                str.push(c);
            }
        }

        return str.size();
    }
};