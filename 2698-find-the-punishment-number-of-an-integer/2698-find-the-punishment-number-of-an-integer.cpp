class Solution {
public:
    bool backtracing(string num, int target){
        if(target < 0) return false;
        else if(stoi(num) == target) return true;

        int n = num.size();
        for(int len = 1; len < n; len++){
            string cutted = num.substr(0, len);
            string remain = num.substr(len);
            if(backtracing(remain, target - stoi(cutted))){
                return true;
            }
        }

        return false;
    }

    int punishmentNumber(int n) {
        int result = 0;
        for(int i = 1; i <= n; i++){
            int square = i * i;
            if(backtracing(to_string(square), i)){
                result += square;
            }
        }
        return result;
    }
};