class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {

        int n = nums.size();

        sort(nums.begin(),nums.end());

        vector<long long> prefix(n,0);

        prefix[0] = nums[0];

        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        vector<long long> ans;

        for(int q : queries){
            long long lb = lower_bound(nums.begin(),nums.end(),q) - nums.begin() - 1;
            long long ub = upper_bound(nums.begin(),nums.end(),q) - nums.begin();

            long long valToInc = 0;
            long long valToDec = 0;

            if(lb!=-1){
                valToInc = q*(lb+1) - (prefix[lb]);
            }
            if(ub!=n){
                valToDec = (prefix[n-1]-(ub>0?prefix[ub-1]:0)) - q*(n-ub);
            }

            ans.push_back(valToInc + valToDec);




        }

        return ans;
        
    }
};