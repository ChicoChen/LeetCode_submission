class NumberContainers {
public:
    NumberContainers() {}
    
    void change(int index, int number) {
        if(nums.contains(index)){
            int original = nums[index];
            indices[original].erase(index);
        }

        indices[number].insert(index);
        nums[index] = number;
    }
    
    int find(int number) {
        if(!indices.contains(number)) return -1;
        return *indices[number].begin();
    }

private:
    unordered_map<int, set<int>> indices;
    unordered_map<int, int> nums;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */