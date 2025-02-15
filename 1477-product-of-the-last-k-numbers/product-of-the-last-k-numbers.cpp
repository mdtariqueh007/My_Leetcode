class ProductOfNumbers {
    private:
    vector<int> prefix;
    int prod;
public:
    ProductOfNumbers() {

        prefix.clear();
        prod = 1;
        
    }
    
    void add(int num) {

        if(num==0){
            prefix.clear();
            prod = 1;
        }
        else{
            prod *= num;
            prefix.push_back(prod);
        }
        
    }
    
    int getProduct(int k) {

        if(k>prefix.size()){
            return 0;
        }

        if(k==prefix.size()){
            return prefix.back();
        }
        else{
            return prefix.back()/prefix[prefix.size() - k - 1];
        }
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */