class Solution {
public:
    int minOperations(vector<string>& logs) {
        std::stack<bool> filepath;
        for(auto &command: logs){
            if(command == "../"){
                if(!filepath.empty())filepath.pop();
            }
            else if(command == "./"){ /*do nothing*/}
            else{filepath.push(true);}
        }
        return filepath.size();
    }
};