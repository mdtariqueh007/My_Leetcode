class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();

        // if(n==1){
        //     return {true};
        // }

        vector<int> notSpecial(n,0);

        for(int  i = 1;i<n;i++){
            if((nums[i]%2)==(nums[i-1]%2)){
                notSpecial[i] = 1;
            }
        }

        
        vector<int> prefix(n,0);

        prefix[0] = notSpecial[0];

        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1] + notSpecial[i];
        }

        vector<bool> ans;

        for(auto q : queries){
            int l = q[0];
            int r = q[1];

            if(prefix[l]==prefix[r]){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }

        return ans;


        
    }
};