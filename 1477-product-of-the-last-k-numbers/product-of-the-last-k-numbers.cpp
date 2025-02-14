class ProductOfNumbers {
    private:
    vector<int> arr;
public:
    ProductOfNumbers() {

        arr.clear();
        
    }
    
    void add(int num) {

        arr.push_back(num);
        
    }
    
    int getProduct(int k) {
        
        int product = 1;

        int n = arr.size();
        for(int i = n-k;i<n;i++){
            product *= arr[i];
        }

        return product;

    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */