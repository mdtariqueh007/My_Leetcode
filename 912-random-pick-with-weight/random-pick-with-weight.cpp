class Solution {
    private:
    vector<int> prefix;
public:
    Solution(vector<int>& w) {

        prefix.push_back(0);

        for(int wi: w){
            prefix.push_back(prefix.back() + wi);
        }
        
    }
    
    int pickIndex() {

        int total = prefix.back();

        int prob = rand() % total;

        int ind = upper_bound(prefix.begin(), prefix.end(), prob) - prefix.begin();

        return ind-1;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */