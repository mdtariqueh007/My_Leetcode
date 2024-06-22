class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n = nums.size();

        int res = 0;

        vector<int> cnt0(n+1,0);
        vector<int> cnt1(n+1,0);

        for(int i = n - 1;i>=0;i--){
            cnt0[i] = cnt0[i+1] + nums[i]==0;
            cnt1[i] = cnt1[i+1] + nums[i]==1;
        }

        bool flag = false;

        for(int i = 0;i<n;i++){
            int val = nums[i];
            if(flag){
                val = 1 - val;
            }
            if(val==0){
                res++;
                swap(cnt0[i+1],cnt1[i+1]);
                flag = !flag;
            }
        }

        return res;
        
    }
};