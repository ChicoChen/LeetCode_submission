class Solution {
public:
    string clearDigits(string s) {
        stack<char> str;
        for(char c: s){
            if(isdigit(c) && !str.empty()){
                str.pop();
            }
            else str.push(c);
        }

        string result = "";
        while(!str.empty()){
            result = str.top() + result;
            str.pop();
        }

        return result;
    }
};