class CustomStack {
    private:
    vector<int> arr;
    int top;
public:
    CustomStack(int maxSize) {

        arr.resize(maxSize);
        top = -1;
        
    }
    
    void push(int x) {

        if(top==arr.size()-1){
            return;
        }

        top++;
        arr[top] = x;


        
    }
    
    int pop() {

        if(top==-1){
            return -1;
        }

        int x = arr[top];
        top--;
        return x;
        
    }
    
    void increment(int k, int val) {

        for(int i = 0;i<min(k,top+1);i++){
            arr[i] += val;
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */