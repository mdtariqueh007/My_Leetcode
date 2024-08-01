class Solution {
    private:
    long long solve(int ind,vector<long long>&prefix,long long k){
        long long ans = -1;
        long long low = ind;
        long long high = (int)prefix.size() - 1;

        while(low<=high){
            int mid = low + (high - low)/2;

            long long length = (mid - ind + 1);
            long long sum = prefix[mid] - (ind==0?0:prefix[ind-1]);
            long long score = sum * length;

            if(score>=k){
                high = mid - 1;
            }
            else{
                ans = mid; 
                low = mid + 1;
            }
        }

        return ans;
    }
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();

        if(n==1 && nums[0]<k){
            return 1;
        }

        vector<long long> prefix(n,0);

        prefix[0] = nums[0];

        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        long long ans = 0;

        for(int i = 0;i<n;i++){
            long long right = solve(i,prefix,k);
            if(right!=-1){
                ans += (right - i + 1);
            }
        }

        return ans;
    }
};