class NumArray {
public:
    vector<int> bit;
    vector<int> arr;
    NumArray(vector<int>& nums) {

        int n = nums.size();
        bit = vector<int>(n+1,0);
        arr = nums;
        for(int i = 0;i<n;i++){
            updateTree(i,arr[i]);
        }
        
    }
    
    void updateTree(int i, int val) {
        i = i + 1;
        for(;i<=arr.size();i += (i&(-i))){
            bit[i] += val;
        }
    }

    int getSum(int i){
        int sum = 0;
        i = i + 1;
        for(;i>0;i -= (i&(-i))){
            sum += bit[i];
        }

        return sum;
    }

    void update(int index,int val){
        int diff = val - arr[index];
        arr[index] = val;
        updateTree(index,diff);
    }
    
    int sumRange(int left, int right) {
        return getSum(right) - getSum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */