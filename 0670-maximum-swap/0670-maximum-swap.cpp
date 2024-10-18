class Solution {
public:
    int maximumSwap(int num) {
        if(num < 10) return num;

        string str = std::to_string(num);
        stack<pair<char, int>> max_stack;
        char max_digit = '0';
        for(int i= str.size() - 1; i>= 0; i--){
            if(str[i] >= max_digit){
                max_digit = str[i];
                max_stack.emplace(str[i], i);
            }
        }

        pair<char, int> element;
        int target = 0;
        while(!max_stack.empty()){
            element = max_stack.top();
            max_stack.pop();

            if(element.second != target){
                while(!max_stack.empty() && max_stack.top().first == element.first){
                    element = max_stack.top();
                    max_stack.pop();
                }
                swap(str[target], str[element.second]);
                return stoi(str);
            }
            target++;
        }
        return stoi(str);
    }
};