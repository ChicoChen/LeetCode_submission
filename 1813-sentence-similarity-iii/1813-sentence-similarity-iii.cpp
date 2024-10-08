class Solution {
public:
    //Updated:
        //time: 0ms faster than 100.00%, memory: 8.7MB, less than 42.42%
        //learn from editorial - use 2-pointer to simulate deque
        //abandon tricky space processing, just use sstream.
    bool areSentencesSimilar(string s1, string s2) {
        std::stringstream ss1(s1), ss2(s2);
        string word;
        vector<string> v1, v2;
        while(ss1 >> word) v1.push_back(word);
        while(ss2 >> word) v2.push_back(word);

        int n1 = v1.size(), n2 = v2.size();
        if(n1 > n2){
            std::swap(n1, n2);
            std::swap(v1, v2);
        }
        
        int head = 0, tail = 0;
        while(head < n1 && v1[head] == v2[head]){
            head++;
        }

        while(tail < n1 && v1[n1 - 1 - tail] == v2[n2 - 1 - tail]){
            tail++;
        }

        return head > (n1 - 1 - tail);
    }
};
