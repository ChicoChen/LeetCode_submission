class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m = s.size();
        int n = part.size();
        
        string result(m, ' ');
        int writehead = 0;
        for(int i = 0; i < m; i++){
            result[writehead] = s[i];
            if(writehead - n + 1 >= 0 && s[i] == part[n - 1]){
                if(result.substr(writehead - n + 1, n) == part)
                    writehead = writehead - n;
            }
            writehead++;
        }

        return result.substr(0, writehead);
    }
};