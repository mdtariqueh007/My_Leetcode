class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        int n = nums.size();

        long long sum = 0;

        for(int x : nums){
            sum = (sum + x)%p;
        }

        int r = sum%p;

        if(r==0){
            return 0;
        }

        int currSum = 0;

        unordered_map<int,int> mp;

        mp[0] = -1;

        int res = n;

        for(int i = 0;i<n;i++){
            int x = nums[i];
            currSum  = (currSum + x)%p;

            int key = (currSum - r +p)%p;

            if(mp.find(key)!=mp.end()){
                res = min(res,i - mp[key]);
            }
            mp[currSum] = i;

        }

        if(res>=n){
            return -1;
        }

        return res;


        
    }
};