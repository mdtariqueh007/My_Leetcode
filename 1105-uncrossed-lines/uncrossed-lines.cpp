class Solution {
    // private:
    // int dp[501][501];
    // int solve(int i, int j, vector<int>&nums1, vector<int>&nums2){
    //     if(i==nums1.size() || j==nums2.size()){
    //         return 0;
    //     }

    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }

    //     if(nums1[i]==nums2[j]){
    //         return dp[i][j] =  1 + solve(i+1, j+1, nums1, nums2);
    //     }
    //     else{
    //         int moveFrom1 = solve(i+1, j, nums1, nums2);
    //         int moveFrom2 = solve(i, j+1, nums1, nums2);

    //         return dp[i][j] = max(moveFrom1, moveFrom2);
    //     }
    // }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        // memset(dp, -1, sizeof(dp));

        // return solve(0, 0, nums1, nums2);

        int m = nums1.size(), n = nums2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = m - 1;i>=0;i--){
            for(int j = n - 1;j>=0;j--){
                if(nums1[i]==nums2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return dp[0][0];
        
    }
};