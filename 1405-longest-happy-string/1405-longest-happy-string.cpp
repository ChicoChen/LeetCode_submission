class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string answer;
        std::priority_queue<pair<int, char>, vector<pair<int, char>>, std::less<>> pq;
        if(a!= 0) pq.emplace(a, 'a');
        if(b!= 0) pq.emplace(b, 'b');
        if(c!= 0)pq.emplace(c, 'c');
        while(!pq.empty()){
            pair<int, char> top = pq.top();
            pq.pop();
            int len = std::min(2, top.first);
            if(!answer.empty() && top.second == answer.back()){
                if(pq.empty()) { break; }
                else{
                    pair<int, char> temp = top;
                    top = pq.top();
                    len = 1;
                    pq.pop();
                    pq.push(temp);
                }
            }
            answer.append(len, top.second);
            if(top.first - len > 0){ pq.emplace(top.first - len, top.second); }
        }

        return answer;
    }
};