class Solution {
    private:
    int memo[20001][4];
    int dp(int ind, int rem, vector<int>&sumOfSubArrays, int k){
        if(rem==0){
            return 0;
        }

        if(ind>=sumOfSubArrays.size()){
            return -1e9;
        }

        if(memo[ind][rem]!=-1){
            return memo[ind][rem];
        }

        int take = sumOfSubArrays[ind] + dp(ind + k, rem - 1, sumOfSubArrays, k);
        int notTake = dp(ind+1, rem, sumOfSubArrays, k);

        return memo[ind][rem] = max(take, notTake);
    }

    void dfs(int ind, int rem, vector<int>& sumOfSubArrays, vector<int>&indices, int k){
        if(rem==0){
            return;
        }

        if(ind>=sumOfSubArrays.size()){
            return;
        }

        int take = sumOfSubArrays[ind] + dp(ind + k, rem - 1, sumOfSubArrays, k);
        int notTake = dp(ind + 1, rem, sumOfSubArrays, k);

        if(take>=notTake){
            indices.push_back(ind);
            dfs(ind + k, rem - 1, sumOfSubArrays, indices, k);
        }
        else{
            dfs(ind + 1, rem, sumOfSubArrays, indices, k);
        }
    }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        int totalSubArrays = n - k + 1;

        vector<int> sumOfSubArrays(totalSubArrays, 0);

        int currWindowSum = 0;

        for(int i = 0;i<k;i++){
            currWindowSum += nums[i];
        }

        sumOfSubArrays[0] = currWindowSum;

        for(int i = k;i<n;i++){
            currWindowSum = currWindowSum - nums[i - k] + nums[i];

            sumOfSubArrays[i - k + 1] = currWindowSum;
        }

        memset(memo, -1, sizeof(memo));

        dp(0,3,sumOfSubArrays, k);

        vector<int> indices;

        memset(memo, -1, sizeof(memo));

        dfs(0,3,sumOfSubArrays,indices, k);

        return indices;



        
    }
};