class Solution {
public:
    //learn from editorial
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        if(n1 == 0) return str2;
        else if(n2 == 0) return str1;
        
        dp.resize(n1 + 1);
        for(int i = 0; i <= n1; i++){
            dp[i].resize(n2 + 1);
            dp[i][0] = i;
        }
        for(int i = 0; i <= n2; i++) dp[0][i] = i;
        
        for(int row = 1; row <= n1; row++){
            for(int col = 1; col <= n2; col++){
                if(str1[row - 1] == str2[col - 1]){
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                }
                else{
                    int s1first = dp[row][col - 1];
                    int s2first = dp[row - 1][col];
                    dp[row][col] = min(s1first, s2first) + 1;
                }
            }
        }

        return reconstruct(str1, str2, n1, n2);
    }

private:
    vector<vector<int>> dp;
    string reconstruct(const string &str1, const string &str2,
                        int row, int col){
        if(row == 0) return str2.substr(0, col);
        else if(col == 0) return str1.substr(0, row);

        if(str1[row - 1] == str2[col - 1]){
            return reconstruct(str1, str2, row - 1, col - 1) + str1[row - 1];
        }
        else if(dp[row][col - 1] < dp[row - 1][col]) {
            return reconstruct(str1, str2, row, col - 1) + str2[col - 1];
        }
        else{
            return reconstruct(str1, str2, row - 1, col) + str1[row - 1];
        }
    }
};