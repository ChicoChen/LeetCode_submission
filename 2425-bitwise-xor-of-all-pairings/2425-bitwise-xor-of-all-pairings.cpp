class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0;
        int xor2 = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i = 0; i < n1; i++){
            xor1 = xor1 ^ nums1[i];
        }

        for(int i = 0; i < n2; i++){
            xor2 = xor2 ^ nums2[i];
        }
        
        if(n2 % 2 == 0 && n1 % 2 == 0){
            return 0;
        }
        else if(n2 % 2 == 0 && n1 % 2 == 1){
            return xor2;
        }
        else if(n1 % 2 == 0){
            return xor1;
        }
        else return xor1 ^ xor2;
    }
};