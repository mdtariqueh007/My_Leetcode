class Solution { 
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();

        vector<int> line(n+1, 0);

        for(auto q: queries){

            int l = q[0];
            int r = q[1];
            int val = 1;

            line[l] += val;
            line[r+1] -= val;
            
        }

        for(int i = 1;i<=n;i++){
            line[i] += line[i-1];
        }

        for(int i = 0;i<n;i++){
            if(line[i]<nums[i]){
                return false;
            }
        }

        return true;
        
    }
};