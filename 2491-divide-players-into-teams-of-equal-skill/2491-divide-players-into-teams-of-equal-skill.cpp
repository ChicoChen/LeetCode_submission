class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long chemistry = 0;
        std::sort(skill.begin(), skill.end());
        int sum = 0;
        for(int num: skill){
            sum += num;
        }
        
        int target = sum / (skill.size() / 2);
        for(int head = 0, tail = skill.size() - 1; head < tail; head++, tail--){
            if(skill[head] + skill[tail] != target){ return -1; }
            chemistry += skill[head] * skill[tail];
        }
        return chemistry;
    }
};