class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        int less = 0, equal = 0;

        for(int x: nums){
            if(x<pivot){
                less++;
            }
            else if(x==pivot){
                equal++;
            }
        }

        vector<int> ans(nums.size());

        int less_i = 0;
        int equal_i = less;
        int greater_i = less + equal;

        for(int x: nums){
            if(x<pivot){
                ans[less_i++] = x;
            }
            else if(x==pivot){
                ans[equal_i++] = x;
            }
            else{
                ans[greater_i++] = x;
            }
        }

        return ans;
        
    }
};