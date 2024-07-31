class Solution {
public:
    //heap sort practice
    //? function calls cause massive overhead, what's the more suitable sorting algorithm?
    void heaplify(vector<int> &nums, int parent, int size){
        int lChild = 2*parent + 1;
        int rChild = 2*parent + 2;
        int max = parent;
        if(lChild < size && nums[lChild] > nums[max]){ max = lChild; }
        if(rChild < size && nums[rChild] > nums[max]){ max = rChild; }

        if(max != parent){
            int temp = nums[parent];
            nums[parent] = nums[max];
            nums[max] = temp;
            heaplify(nums, max, size);
        }
    }

    int largestPerimeter(vector<int>& nums) {
        int lastNonLeaf = nums.size() / 2 - 1;
        for(int i= lastNonLeaf; i>= 0; i--){
            heaplify(nums, i, nums.size());
        }

        for(int i= nums.size() - 1; i > 0; i--){
            int temp = nums[i];
            nums[i] = nums[0];
            nums[0] = temp;
            heaplify(nums, 0, i);
        }
        
        int total = 0;
        for(int i= nums.size() - 1; i >= 2; i--){
            if(nums[i] < nums[i - 1] + nums[i - 2] ){
                total = nums[i] + nums[i - 1] + nums[i - 2];
                break;
            }
        }
        return total;
    }
};
