class Solution {
public:
    string getHappyString(int n, int k) {
        if(k > 3 * pow(2, n - 1)) return "";

        k--;
        string result(n, '0');
        result[0] = 'a' + k / pow(2, n - 1);

        int remainder = k % int(pow(2, n - 1));
        string bitstr;
        for(; remainder > 0; remainder = remainder >> 1){
            if(remainder % 2 == 1) bitstr = "1" + bitstr;
            else bitstr = "0" + bitstr;
        }
        bitstr = string(n - bitstr.size(), '0') + bitstr;

        for(int i = 1; i < n; i++){
            result[i] = (result[i - 1] == 'a')? 'b': 'a';

            if(bitstr[i] == '1'){
                result[i] += (result[i - 1] == 'b')? 2 : 1;
            }
        }

        return result;
    }
};