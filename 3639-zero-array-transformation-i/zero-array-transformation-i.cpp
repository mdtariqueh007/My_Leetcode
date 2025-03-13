class Solution {
    private:
     bool isZeroArray(vector<int>&nums){
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=0){
                return false;
            }
        }

        return true;
    }
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();

        if(isZeroArray(nums)){
            return true;
        }

        vector<int> line(n+1, 0);

        for(auto q: queries){

            int l = q[0];
            int r = q[1];
            int val = 1;

            line[l] -= val;
            line[r+1] += val;
            
        }

        for(int i = 1;i<=n;i++){
            line[i] += line[i-1];
        }

        for(int i = 0;i<n;i++){
            nums[i] = max(nums[i] + line[i], 0);
        }

        if(isZeroArray(nums)){
                return true;
        }

        return false;;
        
    }
};