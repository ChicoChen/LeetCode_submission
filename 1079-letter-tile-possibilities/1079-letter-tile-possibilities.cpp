class Solution {
public:
    //learn from editoral;
    int numTilePossibilities(string tiles) {
        vector<int> permutation(8, 1);
        for(int i = 1; i <= 7; i++){
            permutation[i] = permutation[i - 1] * i;
        }

        int n = tiles.size();
        std::sort(tiles.begin(), tiles.end());
        unordered_set<string> seen;

        return chooseChars("", seen, tiles, 0,permutation);
    }
    int chooseChars(string generated, unordered_set<string> &seen,
                    string tiles, int idx,
                    const vector<int> &permutation){
        if(idx < tiles.size()){
            return chooseChars(generated + tiles[idx], seen, tiles, idx + 1, permutation)
                    + chooseChars(generated, seen, tiles, idx + 1, permutation);
        }
        else if(seen.count(generated) != 0) return 0;
        else if(generated.size() == 0) return 0;

        seen.insert(generated);
        vector<int> count(26, 0);
        for(int i = 0; i < generated.size(); i++){
            count[generated[i] - 'A']++;
        }

        int total = permutation[generated.size()];
        for(int i = 0; i < 26; i++){
            if(count[i] > 1) total /= permutation[count[i]];
        }

        return total;
    }
};