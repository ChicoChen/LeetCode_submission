class Solution {
public:
    //my implementatation
    //todo: optimize, please refer to editorial
    bool areSentencesSimilar(string sentence1, string sentence2) {
        int n1 = sentence1.size(), n2 = sentence2.size();
        //force n1 to be <= n2
        if (n1 > n2) {
            std::swap(sentence1, sentence2);
            std::swap(n1, n2);
        }

        int prefix = 0;
        while (prefix < n1 && sentence1[prefix] == sentence2[prefix]) {
            prefix++;
        }

        // case 1: insert at the end of s1
        if (prefix == n1) {
            //if sentence2[prefix] != ' ' -> s2 != s1 inserted at the end,
            // but still mightbe s1 == s1 inserted at the begining. 
            if(n1 == n2 || sentence2[prefix] == ' '){
                return true;
            }
            
        }

        int suffix = 0;
        while (n1 - 1 - suffix >= 0 &&
              sentence1[n1 - 1 - suffix] == sentence2[n2 - 1 - suffix]) {
            suffix++;
        }
        
        //case 2: insert a the begining of sentence1
        //if n1 == n2, will already return true in prefix-test
        if(suffix == n1){
            return sentence2[n2 - suffix - 1] == ' ';
        }
        else{
            //string not seperate by space.
            if(prefix > 0 && sentence1[prefix - 1] != ' '){
                return false;
            }
            else if(suffix > 0 && sentence1[n1 - suffix] != ' '){
                return false;
            }
        }

        return prefix + suffix >= n1 + 1; //n1 and a repeated ' '
    }
};