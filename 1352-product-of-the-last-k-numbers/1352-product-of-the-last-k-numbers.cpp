class ProductOfNumbers {
public:
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if(num == 0) {
            lastZero = products.size();
            products.push_back(1);
            return;
        }

        if(products.empty()) products.push_back(num);
        else{
            products.push_back(num * products.back());
        }
    }
    
    int getProduct(int k) {
        int n = products.size();
        if(lastZero >= n - k) return 0;

        if(k == n) return products.back();
        else{
            return products.back() / products[n - 1 - k];
        }
    }

    vector<int> products;
    int lastZero = -1;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */