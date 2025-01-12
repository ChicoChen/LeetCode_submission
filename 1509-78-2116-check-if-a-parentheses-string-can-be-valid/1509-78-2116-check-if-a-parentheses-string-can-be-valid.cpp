class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n % 2) return false;

        stack<int> LHS;
        stack<int> free;
        for(int i = 0; i < n; i++){
            if(locked[i] == '0') free.push(i);
            else if(s[i] == '(') LHS.push(i);
            else {
                if(!LHS.empty()) LHS.pop();
                else if(!free.empty()) free.pop();
                else return false;
            }
        }

        while(!LHS.empty()){
            if(free.empty()) return false;
            else if(free.top() < LHS.top()) return false;
            else{
                LHS.pop();
                free.pop();
            }
        }
        
        return free.size() % 2 == 0;
    }
};