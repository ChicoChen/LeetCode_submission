class Solution {
public:
    int nthUglyNumber(int n) {
        //beat 22%, maybe try DP next time
        std:set<long long> que;
        que.insert(1);

        long long answer;
        auto iter = que.begin();
        for(int i= 0; i< n; i++){
            answer = *iter;
            que.insert(answer*2);
            que.insert(answer*3);
            que.insert(answer*5);

            iter++;
        }

        return (int)answer;
    }
};