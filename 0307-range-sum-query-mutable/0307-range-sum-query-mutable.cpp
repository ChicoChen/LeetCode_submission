// exercising: Segement Tree
class NumArray {
private: 
    vector<int> nums;
    int N;
public:
    NumArray(vector<int>& nums) {
        this->N = nums.size();
        this->nums.resize(2 * N, 0);
        std::copy(nums.begin(), nums.end(), this->nums.begin() + N);

        for(int i= N - 1; i > 0; i--){
            this->nums[i] = this->nums[2 * i] + this->nums[2 * i + 1];
        }
    }
    
    void update(int index, int val) {
        index += this->N;
        int diff = val - this->nums[index];
        while(index > 0){
            this->nums[index] += diff;
            index /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        left += this->N;
        right += this->N;
        int count = 0;
        while(left <= right){
            if((left & 1) == 1){ //"left" point at right end of segment
                count += this->nums[left];
                left++;
            }
            if((right & 1) == 0){ //"right" point at left end of segment
                count += this->nums[right];
                right--; //back to right end of remain segment
            }

            left /= 2;  right /= 2;
        }
        return count;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */