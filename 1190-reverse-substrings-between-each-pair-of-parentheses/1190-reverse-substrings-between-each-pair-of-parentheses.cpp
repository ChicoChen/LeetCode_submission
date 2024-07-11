class Solution {
public:
    string reverseParentheses(string s) {
        string answer;
        stack<int> parenthesis;
        int writeHead = 0;
        for(int i= 0; i< s.size(); i++){
            if(s[i] == '(') {
                parenthesis.push(writeHead);
            }
            else if(s[i] == ')'){
                std::reverse(answer.begin() + parenthesis.top(), answer.end());
                parenthesis.pop();
            }
            else{
                answer += s[i];
                writeHead++;
            }
        }
        return answer;
    }
};